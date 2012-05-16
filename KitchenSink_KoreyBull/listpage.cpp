#include "listpage.h"

listPage::listPage(QWidget *parent)
    : tabPage(parent)
{
}


listPage::~listPage( )
{
    delete m_cbox;
    m_cbox = 0;

    delete m_list;
    m_list = 0;

    delete m_suggest;
    m_suggest = 0;

    delete m_complete;
    m_complete = 0;

    delete m_treew;
    m_treew = 0;
}


void listPage::initializePage(const KitchenSink * sink)
{

    tabPage::performBasicSetup(LIST);

    // widget creation
    QLabel * slabel = new QLabel("Suggest box:");
    m_cbox = new QComboBox;
    m_list = new QListWidget;
    m_suggest = new QLineEdit;
    m_complete = new QCompleter(SinkModel::getInstance().getSuggestionList());
    m_treew = new QTreeWidget;

    // settings / setup
    m_cbox->setBaseSize(57, 18);
    m_cbox->setMaximumSize(57, 18);

    for (int i = 0; i < 5; ++i)
    {
        m_cbox->insertItem(i, tr("List %1").arg(i));
    }

    m_list->setBaseSize(56, 169);
    m_list->setMaximumSize(56, 169);
    m_list->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    m_list->addItem("foo()");
    m_list->addItem("bar()");
    m_list->addItem("baz()");
    m_list->addItem("toto()");
    m_list->addItem("tintin()");

    m_complete->setCaseSensitivity(Qt::CaseInsensitive);
    m_suggest->setCompleter(m_complete);
    m_suggest->setBaseSize(151, 16);
    m_suggest->setMaximumSize(151, 16);
    m_suggest->setObjectName("suggestBox");

    initTree();

    // layouts
    QHBoxLayout * layout = new QHBoxLayout;
    QVBoxLayout * vlayout = new QVBoxLayout;

    layout->addWidget(m_cbox, 0, Qt::AlignLeft | Qt::AlignTop);
    layout->addWidget(m_list, 0, Qt::AlignCenter);

    vlayout->addWidget(slabel);
    vlayout->addWidget(m_suggest);

    layout->addLayout(vlayout, 0);
    layout->addWidget(m_treew, 0, Qt::AlignCenter);

    tabPage::m_pageLayout->addRow(layout);

    // connections and layout merging
    setLayout(tabPage::m_pageLayout);
    setStyleSheet(SinkModel::getInstance().getStyleSheet(LIST));
    // anything else?
}


Tabs listPage::getTabKey( ) const
{
    return LIST;
}


void listPage::initTree()
{
    m_treew->setBaseSize(266, 66);
    m_treew->setBaseSize(266, 66);
    m_treew->setColumnCount(1);
    m_treew->setHeaderItem(0);

    QMap<SongType, QStringList> songSet;
    QMap<SongType, QString> types;
    QList<QTreeWidgetItem *> items;
    QList<QTreeWidgetItem *> more;
    QList<QTreeWidgetItem *> children;

    for (int i = 0; i < ARTIST_MAX; ++i)
    {
        items.append(new QTreeWidgetItem(QStringList(SinkModel::getInstance().getArtistName((Artists)i))));
    }

    m_treew->insertTopLevelItems(0, items);
    types = SinkModel::getInstance().getSongTypes();

    for (int i = 0; i < ARTIST_MAX; ++i)
    {
        songSet = SinkModel::getInstance().getArtistWorks((Artists)i);

        for (int s = 0; s < SONGTYPE_MAX; ++s)
        {
            if (songSet.contains((SongType)s))
                more.append(new QTreeWidgetItem(QStringList(types[(SongType)s])));
        }

        items[i]->insertChildren(0, more);

        for (int s = 0; s < SONGTYPE_MAX; ++s)
        {
            if (songSet.contains((SongType)s))
            {
                foreach (QString song, songSet[(SongType)s])
                {
                    children.append(new QTreeWidgetItem(QStringList(song)));
                }

                more[s]->insertChildren(more[s]->childCount(), children);
            }

            children.clear();
        }

        more.clear();
    }
}
