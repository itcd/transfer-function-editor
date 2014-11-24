/********************************************************************************
** Form generated from reading UI file 'transferfunctioneditor.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFERFUNCTIONEDITOR_H
#define UI_TRANSFERFUNCTIONEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TransferFunctionEditor
{
public:
    QAction *action_Open_Transfer_Function;
    QAction *action_Save_Transfer_Function;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *diagonalButton;
    QPushButton *levelButton;
    QPushButton *distributeHorizontallyButton;
    QPushButton *distributeVerticallyButton;

    void setupUi(QMainWindow *TransferFunctionEditor)
    {
        if (TransferFunctionEditor->objectName().isEmpty())
            TransferFunctionEditor->setObjectName(QStringLiteral("TransferFunctionEditor"));
        TransferFunctionEditor->resize(640, 480);
        action_Open_Transfer_Function = new QAction(TransferFunctionEditor);
        action_Open_Transfer_Function->setObjectName(QStringLiteral("action_Open_Transfer_Function"));
        action_Save_Transfer_Function = new QAction(TransferFunctionEditor);
        action_Save_Transfer_Function->setObjectName(QStringLiteral("action_Save_Transfer_Function"));
        centralWidget = new QWidget(TransferFunctionEditor);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        horizontalLayout->addLayout(verticalLayout);

        TransferFunctionEditor->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TransferFunctionEditor);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 26));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        TransferFunctionEditor->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TransferFunctionEditor);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TransferFunctionEditor->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TransferFunctionEditor);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TransferFunctionEditor->setStatusBar(statusBar);
        dockWidget = new QDockWidget(TransferFunctionEditor);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        horizontalLayout_2 = new QHBoxLayout(dockWidgetContents);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        diagonalButton = new QPushButton(dockWidgetContents);
        diagonalButton->setObjectName(QStringLiteral("diagonalButton"));

        horizontalLayout_2->addWidget(diagonalButton);

        levelButton = new QPushButton(dockWidgetContents);
        levelButton->setObjectName(QStringLiteral("levelButton"));

        horizontalLayout_2->addWidget(levelButton);

        distributeHorizontallyButton = new QPushButton(dockWidgetContents);
        distributeHorizontallyButton->setObjectName(QStringLiteral("distributeHorizontallyButton"));

        horizontalLayout_2->addWidget(distributeHorizontallyButton);

        distributeVerticallyButton = new QPushButton(dockWidgetContents);
        distributeVerticallyButton->setObjectName(QStringLiteral("distributeVerticallyButton"));

        horizontalLayout_2->addWidget(distributeVerticallyButton);

        dockWidget->setWidget(dockWidgetContents);
        TransferFunctionEditor->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidget);

        menuBar->addAction(menu_File->menuAction());
        menu_File->addAction(action_Open_Transfer_Function);
        menu_File->addAction(action_Save_Transfer_Function);

        retranslateUi(TransferFunctionEditor);

        QMetaObject::connectSlotsByName(TransferFunctionEditor);
    } // setupUi

    void retranslateUi(QMainWindow *TransferFunctionEditor)
    {
        TransferFunctionEditor->setWindowTitle(QApplication::translate("TransferFunctionEditor", "Transfer Function Editor", 0));
        action_Open_Transfer_Function->setText(QApplication::translate("TransferFunctionEditor", "&Open Transfer Function...", 0));
        action_Save_Transfer_Function->setText(QApplication::translate("TransferFunctionEditor", "&Save Transfer Function...", 0));
        menu_File->setTitle(QApplication::translate("TransferFunctionEditor", "&File", 0));
        diagonalButton->setText(QApplication::translate("TransferFunctionEditor", "diagonal ramp", 0));
        levelButton->setText(QApplication::translate("TransferFunctionEditor", "level", 0));
        distributeHorizontallyButton->setText(QApplication::translate("TransferFunctionEditor", "distribute horizontally", 0));
        distributeVerticallyButton->setText(QApplication::translate("TransferFunctionEditor", "distribute vertically", 0));
    } // retranslateUi

};

namespace Ui {
    class TransferFunctionEditor: public Ui_TransferFunctionEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFERFUNCTIONEDITOR_H
