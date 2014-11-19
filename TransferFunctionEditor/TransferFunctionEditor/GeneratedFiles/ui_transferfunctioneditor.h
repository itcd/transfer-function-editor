/********************************************************************************
** Form generated from reading UI file 'transferfunctioneditor.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFERFUNCTIONEDITOR_H
#define UI_TRANSFERFUNCTIONEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TransferFunctionEditorClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TransferFunctionEditorClass)
    {
        if (TransferFunctionEditorClass->objectName().isEmpty())
            TransferFunctionEditorClass->setObjectName(QStringLiteral("TransferFunctionEditorClass"));
        TransferFunctionEditorClass->resize(600, 400);
        menuBar = new QMenuBar(TransferFunctionEditorClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        TransferFunctionEditorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TransferFunctionEditorClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TransferFunctionEditorClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(TransferFunctionEditorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TransferFunctionEditorClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TransferFunctionEditorClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TransferFunctionEditorClass->setStatusBar(statusBar);

        retranslateUi(TransferFunctionEditorClass);

        QMetaObject::connectSlotsByName(TransferFunctionEditorClass);
    } // setupUi

    void retranslateUi(QMainWindow *TransferFunctionEditorClass)
    {
        TransferFunctionEditorClass->setWindowTitle(QApplication::translate("TransferFunctionEditorClass", "TransferFunctionEditor", 0));
    } // retranslateUi

};

namespace Ui {
    class TransferFunctionEditorClass: public Ui_TransferFunctionEditorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFERFUNCTIONEDITOR_H
