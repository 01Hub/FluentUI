#ifndef FLUTHEME_H
#define FLUTHEME_H

#include <QObject>
#include <QtQml/qqml.h>
#include <QQmlEngine>
#include "FluColorSet.h"
#include "stdafx.h"

/**
 * @brief The FluTheme class
 */
class FluTheme : public QObject
{
    Q_OBJECT
    /**
     * @brief dark 改变窗口夜间样式，只读属性，可以通过darkMode切换
     */
    Q_PROPERTY(bool dark READ dark NOTIFY darkChanged)

    /**
     * @brief primaryColor 主题颜色
     */
    Q_PROPERTY_AUTO(FluColorSet*,primaryColor)

    /**
     * @brief darkMode 夜间模式，支持System=0、Light=1、Dark=2
     */
    Q_PROPERTY_AUTO(int,darkMode);

    /**
     * @brief nativeText 本地渲染文本
     */
    Q_PROPERTY_AUTO(bool,nativeText);

    QML_NAMED_ELEMENT(FluTheme)
    QML_SINGLETON
private:
    static FluTheme* m_instance;
    explicit FluTheme(QObject *parent = nullptr);
public:
    static QJSValue create(QQmlEngine *qmlEngine, QJSEngine *jsEngine);
    static FluTheme *getInstance();
    bool dark();
    Q_SIGNAL void darkChanged();
    void setJsValue(QJSValue value){
        m_jsvalue =value;
    }
    Q_INVOKABLE QJSValue getJsValue(){
        return m_jsvalue;
    }
private:
    bool _dark;
    bool _systemDark;
    QJSValue m_jsvalue;
    bool eventFilter(QObject *obj, QEvent *event);
    bool systemDark();
};

#endif // FLUTHEME_H
