#include <QtQml/qqmlprivate.h>
#include <QtCore/qdir.h>
#include <QtCore/qurl.h>
#include <QtCore/qhash.h>
#include <QtCore/qstring.h>

namespace QmlCacheGeneratedCode {
namespace _qt_qml_vehicleDashboardQML_Main_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::TypedFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_vehicleDashboardQML_Speedometer_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::TypedFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_vehicleDashboardQML_FuelGauge_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::TypedFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_vehicleDashboardQML_DigitalClock_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::TypedFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_vehicleDashboardQML_TurnIndicators_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::TypedFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_vehicleDashboardQML_DashboardShape_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::TypedFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_vehicleDashboardQML_TotalKm_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::TypedFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}

}
namespace {
struct Registry {
    Registry();
    ~Registry();
    QHash<QString, const QQmlPrivate::CachedQmlUnit*> resourcePathToCachedUnit;
    static const QQmlPrivate::CachedQmlUnit *lookupCachedUnit(const QUrl &url);
};

Q_GLOBAL_STATIC(Registry, unitRegistry)


Registry::Registry() {
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/vehicleDashboardQML/Main.qml"), &QmlCacheGeneratedCode::_qt_qml_vehicleDashboardQML_Main_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/vehicleDashboardQML/Speedometer.qml"), &QmlCacheGeneratedCode::_qt_qml_vehicleDashboardQML_Speedometer_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/vehicleDashboardQML/FuelGauge.qml"), &QmlCacheGeneratedCode::_qt_qml_vehicleDashboardQML_FuelGauge_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/vehicleDashboardQML/DigitalClock.qml"), &QmlCacheGeneratedCode::_qt_qml_vehicleDashboardQML_DigitalClock_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/vehicleDashboardQML/TurnIndicators.qml"), &QmlCacheGeneratedCode::_qt_qml_vehicleDashboardQML_TurnIndicators_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/vehicleDashboardQML/DashboardShape.qml"), &QmlCacheGeneratedCode::_qt_qml_vehicleDashboardQML_DashboardShape_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/vehicleDashboardQML/TotalKm.qml"), &QmlCacheGeneratedCode::_qt_qml_vehicleDashboardQML_TotalKm_qml::unit);
    QQmlPrivate::RegisterQmlUnitCacheHook registration;
    registration.structVersion = 0;
    registration.lookupCachedQmlUnit = &lookupCachedUnit;
    QQmlPrivate::qmlregister(QQmlPrivate::QmlUnitCacheHookRegistration, &registration);
}

Registry::~Registry() {
    QQmlPrivate::qmlunregister(QQmlPrivate::QmlUnitCacheHookRegistration, quintptr(&lookupCachedUnit));
}

const QQmlPrivate::CachedQmlUnit *Registry::lookupCachedUnit(const QUrl &url) {
    if (url.scheme() != QLatin1String("qrc"))
        return nullptr;
    QString resourcePath = QDir::cleanPath(url.path());
    if (resourcePath.isEmpty())
        return nullptr;
    if (!resourcePath.startsWith(QLatin1Char('/')))
        resourcePath.prepend(QLatin1Char('/'));
    return unitRegistry()->resourcePathToCachedUnit.value(resourcePath, nullptr);
}
}
int QT_MANGLE_NAMESPACE(qInitResources_qmlcache_appvehicleDashboardQML)() {
    ::unitRegistry();
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_qmlcache_appvehicleDashboardQML))
int QT_MANGLE_NAMESPACE(qCleanupResources_qmlcache_appvehicleDashboardQML)() {
    return 1;
}
