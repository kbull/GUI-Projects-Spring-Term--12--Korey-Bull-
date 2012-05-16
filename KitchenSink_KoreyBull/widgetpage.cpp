#include "widgetpage.h"
#include <QWidgetAction>


widgetPage::widgetPage(QWidget * parent)
    : tabPage(parent), m_menu(0), m_enabledCheck(0),
      m_disabledCheck(0)
{
    for (short i = 0; i < BUTTONS; ++i)
    {
        m_pushButtons[i] = 0;
        m_choices[i] = 0;
    }
}


widgetPage::~widgetPage( )
{
    for (short i = 0; i < BUTTONS; ++i)
    {
        delete m_pushButtons[i];
        m_pushButtons[i] = 0;

        delete m_choices[i];
        m_choices[i] = 0;
    }

    delete m_menu;
    m_menu = 0;

    delete m_enabledCheck;
    m_enabledCheck = 0;

    delete m_disabledCheck;
    m_disabledCheck = 0;

}


void widgetPage::initializePage(const KitchenSink * sink)
{
    tabPage::performBasicSetup(WIDGET);
    QGridLayout * gridLayout = new QGridLayout;
    QHBoxLayout * hLayout[4] = {0};


    for (short i = 0; i < BUTTONS; ++i)
    {
        m_pushButtons[i] = new QPushButton;
        m_choices[i] = new QRadioButton(this);
        hLayout[i] = new QHBoxLayout;
    }

    initializeMenu();

    m_enabledCheck = new QCheckBox("Normal Check");
    m_enabledCheck->setEnabled(true);
    m_disabledCheck = new QCheckBox("Disabled Check");
    m_disabledCheck->setEnabled(false);

    m_pushButtons[0]->setEnabled(true);
    m_pushButtons[0]->setText("Normal Button");
    m_pushButtons[0]->setMinimumSize(154, 16);
    m_pushButtons[0]->setMaximumSize(154, 16);
    m_pushButtons[1]->setEnabled(false);
    m_pushButtons[1]->setText("Disabled Button");
    m_pushButtons[1]->setMinimumSize(154, 16);
    m_pushButtons[1]->setMaximumSize(154, 16);
    m_pushButtons[2]->setObjectName("squareButton");
    m_pushButtons[2]->setMinimumSize(95, 75);
    m_pushButtons[2]->setBaseSize(95, 75);
    m_pushButtons[2]->setFlat(true);
    m_pushButtons[3]->setObjectName("squareToggle");
    m_pushButtons[3]->setMinimumSize(95, 75);
    m_pushButtons[3]->setBaseSize(95, 75);
    m_pushButtons[3]->setCheckable(true);

    initializeOpts( );

    // layout additional elements
    m_menu->setMinimumSize(390, 22);
    m_menu->setBaseSize(390, 22);
    //gridLayout->addItem(new QSpacerItem(10, 10), 0, 4);
    gridLayout->addWidget(m_menu, 0, 0, 1, 8, Qt::AlignLeft);
    gridLayout->addItem(new QSpacerItem(10, 15), 1, 4);

    hLayout[0]->addSpacerItem(new QSpacerItem(2, 1));
    hLayout[0]->addWidget(m_pushButtons[0], 0, Qt::AlignHCenter);
    hLayout[0]->addSpacerItem(new QSpacerItem(2, 1));
    hLayout[0]->addWidget(m_pushButtons[1], 0, Qt::AlignHCenter);
    hLayout[0]->addSpacerItem(new QSpacerItem(2, 1));

    gridLayout->addLayout(hLayout[0], 2, 0, 1, 8, Qt::AlignLeft);
    gridLayout->addItem(new QSpacerItem(10, 15), 3, 4);

    hLayout[1]->addWidget(m_enabledCheck, 0, Qt::AlignLeft);
    hLayout[1]->addWidget(m_disabledCheck, 0, Qt::AlignLeft);
    gridLayout->addLayout(hLayout[1], 4, 0, 1, 8, Qt::AlignLeft);

    for (short i = 0; i < BUTTONS; ++i)
    {
        hLayout[2]->addWidget(m_choices[i], 0, Qt::AlignLeft);
    }

    gridLayout->addItem(new QSpacerItem(10, 15), 5, 4);
    gridLayout->addLayout(hLayout[2], 6, 0, 1, 8, Qt::AlignLeft);
    gridLayout->addItem(new QSpacerItem(10, 15), 7, 4);

    hLayout[3]->addWidget(m_pushButtons[2], 0, Qt::AlignLeft);
    hLayout[3]->addWidget(m_pushButtons[3], 0, Qt::AlignLeft);

    m_pushButtons[1]->setDown(true);

    gridLayout->addLayout(hLayout[3], 8, 0, 1, 8, Qt::AlignLeft);

    tabPage::m_pageLayout->addRow(gridLayout);
    tabPage::m_pageLayout->setAlignment(gridLayout, Qt::AlignHCenter);

    setLayout(tabPage::m_pageLayout);

    // style sheet(s)
    setStyleSheet(SinkModel::getInstance().getStyleSheet(WIDGET));

    //connect events
    connect(m_menu, SIGNAL(triggered(QAction*)), sink, SLOT(menuActionBox()));
}


Tabs widgetPage::getTabKey( ) const
{
    return WIDGET;
}


void widgetPage::initializeMenu( )
{
    QMenu * menu = 0;
    QWidgetAction * action = 0;
    QLabel * boldL = 0, * italicL = 0, * redL = 0, * whiteL = 0, * brownL = 0;
    QLabel * yellowL = 0, * codeL = 0, * underL = 0, * strikeL = 0, * wootL = 0;
    m_menu = new QMenuBar;

    menu = m_menu->addMenu("Style");

    boldL = new QLabel("Bold");
    boldL->setObjectName("boldL");
    action = new QWidgetAction(this);
    action->setDefaultWidget(boldL);
    menu->addAction(action);

    italicL = new QLabel("Italic");
    italicL->setObjectName("italicL");
    action = new QWidgetAction(this);
    action->setDefaultWidget(italicL);
    menu->addAction(action);

    menu = menu->addMenu("More >>");

    codeL = new QLabel("<code>Code</code>");
    codeL->setObjectName("codeL");
    action = new QWidgetAction(this);
    action->setDefaultWidget(codeL);
    menu->addAction(action);

    strikeL = new QLabel("Strikethrough");
    strikeL->setObjectName("strikeL");
    action = new QWidgetAction(this);
    action->setDefaultWidget(strikeL);
    menu->addAction(action);

    underL = new QLabel("Underlined");
    underL->setObjectName("underL");
    action = new QWidgetAction(this);
    action->setDefaultWidget(underL);
    menu->addAction(action);


    menu = m_menu->addMenu("Fruit");

    redL = new QLabel("Apple");
    redL->setObjectName("redL");
    action = new QWidgetAction(this);
    action->setDefaultWidget(redL);
    menu->addAction(action);

    yellowL = new QLabel("Banana");
    yellowL->setObjectName("yellowL");
    action = new QWidgetAction(this);
    action->setDefaultWidget(yellowL);
    menu->addAction(action);

    whiteL = new QLabel("Coconut");
    whiteL->setObjectName("whiteL");
    action = new QWidgetAction(this);
    action->setDefaultWidget(whiteL);
    menu->addAction(action);

    brownL = new QLabel("Donut");
    brownL->setObjectName("brownL");
    action = new QWidgetAction(this);
    action->setDefaultWidget(brownL);
    menu->addAction(action);

    menu = m_menu->addMenu("Term");

    menu->addAction("Bling");
    menu->addAction("Ginormous");

    wootL = new QLabel("w00t!");
    wootL->setObjectName("wootL");
    action = new QWidgetAction(this);
    action->setDefaultWidget(wootL);
    menu->addAction(action);

    menu = m_menu->addMenu("    ");
    menu->setEnabled(false);

    menu = m_menu->addMenu("    ");
    menu->setEnabled(false);

    menu = m_menu->addMenu("    ");
    menu->setEnabled(false);

    menu = m_menu->addMenu("    ");
    menu->setEnabled(false);

    menu = m_menu->addMenu("    ");
    menu->setEnabled(false);

    menu = m_menu->addMenu("    ");
    menu->setEnabled(false);

    menu = m_menu->addMenu("    ");
    menu->setEnabled(false);
}


void widgetPage::initializeOpts( )
{
    QString temp0 = "Choice %1", temp = "";

    for (short i = 0; i < BUTTONS; ++i)
    {
        temp = temp0.arg(i);

        if (i == 2)
        {
            temp += "(Disabled)";
            m_choices[i]->setDisabled(true);
        }

        m_choices[i]->setText(temp);
    }
}
