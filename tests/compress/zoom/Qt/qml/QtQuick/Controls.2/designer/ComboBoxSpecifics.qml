/****************************************************************************
**
** Copyright (C) 2021 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Quick Controls 2 module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:COMM$
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** $QT_END_LICENSE$
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
****************************************************************************/

import QtQuick 2.12
import HelperWidgets 2.0
import QtQuick.Layouts 1.12

Column {
    width: parent.width

    Section {
        width: parent.width
        caption: qsTr("ComboBox")

        SectionLayout {
            Label {
                text: qsTr("Text Role")
                tooltip: qsTr("The model role used for displaying text.")
            }
            SecondColumnLayout {
                LineEdit {
                    backendValue: backendValues.textRole
                    Layout.fillWidth: true
                }
            }

            Label {
                text: qsTr("Current")
                tooltip: qsTr("The index of the current item.")
            }
            SecondColumnLayout {
                SpinBox {
                    maximumValue: 9999999
                    minimumValue: -9999999
                    decimals: 0
                    backendValue: backendValues.currentIndex
                    Layout.fillWidth: true
                }
            }
        Label {
            text: qsTr("Editable")
            tooltip: qsTr("Whether the combo box is editable.")
        }
        SecondColumnLayout {
            CheckBox {
                text: backendValues.editable.valueToString
                backendValue: backendValues.editable
                Layout.fillWidth: true
            }
        }
        Label {
            text: qsTr("Flat")
            tooltip: qsTr("Whether the combo box button is flat.")
        }
        SecondColumnLayout {
            CheckBox {
                text: backendValues.flat.valueToString
                backendValue: backendValues.flat
                Layout.fillWidth: true
            }
        }
        Label {
                text: qsTr("DisplayText")
                tooltip: qsTr("Holds the text that is displayed on the combo box button.")
            }
            SecondColumnLayout {
                LineEdit {
                    backendValue: backendValues.displayText
                    Layout.fillWidth: true
                }
            }
        }
    }

    ControlSection {
        width: parent.width
    }

    FontSection {
        width: parent.width
    }

    PaddingSection {
        width: parent.width
    }
}