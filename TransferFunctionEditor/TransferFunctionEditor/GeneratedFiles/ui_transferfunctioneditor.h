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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TransferFunctionEditor
{
public:
    QAction *action_Load_Transfer_Function;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TransferFunctionEditor)
    {
        if (TransferFunctionEditor->objectName().isEmpty())
            TransferFunctionEditor->setObjectName(QStringLiteral("TransferFunctionEditor"));
        TransferFunctionEditor->resize(400, 300);
        action_Load_Transfer_Function = new QAction(TransferFunctionEditor);
        action_Load_Transfer_Function->setObjectName(QStringLiteral("action_Load_Transfer_Function"));
        centralWidget = new QWidget(TransferFunctionEditor);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        TransferFunctionEditor->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TransferFunctionEditor);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 26));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        TransferFunctionEditor->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TransferFunctionEditor);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TransferFunctionEditor->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TransferFunctionEditor);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TransferFunctionEditor->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menu_File->addAction(action_Load_Transfer_Function);

        retranslateUi(TransferFunctionEditor);

        QMetaObject::connectSlotsByName(TransferFunctionEditor);
    } // setupUi

    void retranslateUi(QMainWindow *TransferFunctionEditor)
    {
        TransferFunctionEditor->setWindowTitle(QApplication::translate("TransferFunctionEditor", "TransferFunctionEditor", 0));
        action_Load_Transfer_Function->setText(QApplication::translate("TransferFunctionEditor", "&Load Transfer Function...", 0));
        menu_File->setTitle(QApplication::translate("TransferFunctionEditor", "&File", 0));
    } // retranslateUi

};

namespace Ui {
    class TransferFunctionEditor: public Ui_TransferFunctionEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFERFUNCTIONEDITOR_H
