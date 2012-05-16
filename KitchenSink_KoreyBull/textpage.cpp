#include "textpage.h"

#define LINE_EDIT_CT 4



textPage::textPage(QWidget * parent)
    : tabPage(parent), m_textEditor(0), m_cursPos(0),
      m_labels(0), m_lineEdits(0)
{

}


textPage::~textPage( )
{
    for (qint8 i = 0; i < LINE_EDIT_CT; ++i)
    {
        delete m_lineEdits[i];
        m_lineEdits[i] = 0;

        if (i < (LINE_EDIT_CT - 1))
        {
            delete m_cursPos[i];
            m_cursPos[i] = 0;

            delete m_labels[i];
            m_labels[i] = 0;
        }
    }

    delete [] m_lineEdits;
    m_lineEdits = 0;

    delete [] m_labels;
    m_labels = 0;

    delete [] m_cursPos;
    m_cursPos = 0;

    delete m_textEditor;
    m_textEditor = 0;
}


void textPage::initializePage(const KitchenSink * sink)
{
    QHBoxLayout * pageLay = new QHBoxLayout;
    QVBoxLayout * leftLay = new QVBoxLayout;
    QHBoxLayout * textLay[3] = {0};

    tabPage::performBasicSetup(TEXT);

    instantiateWidgets(textLay);

    // layouts & setup
    m_labels[0]->setText("Normal text box:");
    m_labels[1]->setText("Password text box:");
    m_labels[2]->setText("Text area:");

    m_cursPos[0]->setText("Selection:");
    m_cursPos[1]->setText("Selection:");
    m_cursPos[2]->setText("Selection:");

    m_lineEdits[0]->setObjectName("normalTextEdit");
    m_lineEdits[1]->setObjectName("readOnlyTextEdit");
    m_lineEdits[1]->setReadOnly(true);
    m_lineEdits[1]->setBaseSize(m_lineEdits[0]->width(), m_lineEdits[1]->height());
    m_lineEdits[1]->setPlaceholderText("read only");
    m_lineEdits[2]->setObjectName("passwordTextEdit");
    m_lineEdits[3]->setObjectName("textAreaTextEdit");
    m_lineEdits[3]->setBaseSize(m_lineEdits[3]->width(), m_lineEdits[3]->height() * 4);

    setupHLayouts(textLay);

    leftLay->addWidget(m_labels[0]);
    leftLay->addLayout(textLay[0]);
    leftLay->addWidget(m_lineEdits[1]);
    leftLay->addWidget(m_labels[1]);
    leftLay->addLayout(textLay[1]);
    leftLay->addWidget(m_labels[2]);
    leftLay->addLayout(textLay[2]);

    pageLay->addLayout(leftLay);
    pageLay->addSpacerItem(new QSpacerItem(2, 2, QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding));
    pageLay->addWidget(m_textEditor);

    // do some stuff for the text editor maybe etc
    //combine layouts, connections
    tabPage::m_pageLayout->addRow(pageLay);
    setLayout(tabPage::m_pageLayout);
    setStyleSheet(SinkModel::getInstance().getStyleSheet(TEXT));

    // connect events
    connect(m_lineEdits[0], SIGNAL(cursorPositionChanged(int,int)), sink, SLOT(normCursorChg(int,int)));
    connect(m_lineEdits[0], SIGNAL(selectionChanged()), sink, SLOT(normSelectionChg()));
    connect(m_lineEdits[2], SIGNAL(cursorPositionChanged(int,int)), sink, SLOT(passCursorChg(int,int)));
    connect(m_lineEdits[2], SIGNAL(selectionChanged()), sink, SLOT(passSelectionChg()));
    connect(m_lineEdits[3], SIGNAL(cursorPositionChanged(int,int)), sink, SLOT(textCursorChg(int,int)));
    connect(m_lineEdits[3], SIGNAL(selectionChanged()), sink, SLOT(textSelectionChg()));

    SinkModel::getInstance().setNormalEdit(m_lineEdits[0]);
    SinkModel::getInstance().setPassEdit(m_lineEdits[2]);
    SinkModel::getInstance().setTextEdit(m_lineEdits[3]);

    SinkModel::getInstance().setNormalCurs(m_cursPos[0]);
    SinkModel::getInstance().setPassCurs(m_cursPos[1]);
    SinkModel::getInstance().setTextCurs(m_cursPos[2]);
}


Tabs textPage::getTabKey( ) const
{
    return TEXT;
}


void textPage::instantiateWidgets(QHBoxLayout *textLay[])
{
    m_cursPos = new QLabel * [3];
    m_labels = new QLabel * [3];
    m_lineEdits = new QLineEdit * [LINE_EDIT_CT];


    for (qint8 i = 0; i < LINE_EDIT_CT; ++i)
    {
        m_lineEdits[i] = new QLineEdit;

        if (i < (LINE_EDIT_CT - 1))
        {
            textLay[i] = new QHBoxLayout;
            m_cursPos[i] = new QLabel;
            m_labels[i] = new QLabel;
        }
    }

    m_textEditor = new QTextEdit;
}


void textPage::setupHLayouts(QHBoxLayout *textLay[])
{
    qint8 i = 0;

    textLay[i]->addWidget(m_lineEdits[i]);
    textLay[i]->addSpacerItem(new QSpacerItem(2, 2));
    textLay[i]->addWidget(m_cursPos[i]);

    ++i; // 0 ==> 1

    textLay[i]->addWidget(m_lineEdits[i + 1]);
    textLay[i]->addSpacerItem(new QSpacerItem(2, 2));
    textLay[i]->addWidget(m_cursPos[i]);

    ++i; // 1 ==> 2

    textLay[i]->addWidget(m_lineEdits[i + 1]);
    textLay[i]->addSpacerItem(new QSpacerItem(2, 2));
    textLay[i]->addWidget(m_cursPos[i]);
}
