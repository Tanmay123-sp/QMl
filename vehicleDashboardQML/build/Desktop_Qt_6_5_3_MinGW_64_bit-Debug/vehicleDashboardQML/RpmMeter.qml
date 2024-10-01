import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: rpmMeterContainer
    width: 300
    height: 300

    property real speed: 0 // Speed property that you can modify to see the effect
    property real rpm: 0 // RPM property based on speed

    // Timer to simulate speed increase
    Timer {
        interval: 100 // Adjust the interval as needed
        repeat: true
        running: true
        onTriggered: {
            if (speed > 0) {
                rpm = Math.min(rpm + 5, speed * 100); // Increase RPM based on speed
            } else {
                rpm = 0; // Reset RPM when speed is 0
            }
            speed = Math.min(speed + 1, 120); // Simulate speed increase
        }
    }

    Canvas {
        id: rpmCanvas
        width: 300
        height: 300

        onPaint: {
            var ctx = getContext("2d")
            var centerX = width / 2
            var centerY = height / 2
            var gaugeRadius = 120
            var startAngle = Math.PI; // Start from the left side
            var endAngle = 2 * Math.PI; // Go to the right side

            ctx.clearRect(0, 0, width, height)

            // Draw RPM Meter Background
            ctx.beginPath()
            ctx.arc(centerX, centerY, gaugeRadius, startAngle, endAngle, false)
            ctx.fillStyle = "#1C2D3C"
            ctx.fill()
            ctx.lineWidth = 5
            ctx.strokeStyle = "#3A6075"
            ctx.stroke()
            ctx.closePath()

            // Draw RPM Needle
            if (rpm > 0) {
                var needleAngle = (rpm / 120) * Math.PI + Math.PI; // Convert RPM to angle
                var needleEndX = centerX + (gaugeRadius - 20) * Math.cos(needleAngle);
                var needleEndY = centerY + (gaugeRadius - 20) * Math.sin(needleAngle);
                ctx.lineWidth = 4
                ctx.strokeStyle = "#FF4500"
                ctx.beginPath()
                ctx.moveTo(centerX, centerY)
                ctx.lineTo(needleEndX, needleEndY)
                ctx.stroke()
                ctx.closePath()
            }

            // Draw RPM Labels
            ctx.fillStyle = "#FFFFFF"
            ctx.font = "16px Arial"
            ctx.textAlign = "center"
            ctx.textBaseline = "middle"

            for (var i = 0; i <= 120; i += 20) {
                if (i > 0) {
                    var angle = (i / 120) * Math.PI + Math.PI; // Calculate angle for each label
                    var labelX = centerX + (gaugeRadius - 30) * Math.cos(angle); // Positioning the label
                    var labelY = centerY + (gaugeRadius - 30) * Math.sin(angle);
                    ctx.fillText(i.toString(), labelX, labelY); // Draw the label
                }
            }
        }
    }
}
