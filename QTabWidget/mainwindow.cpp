#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QTableWidget>//表格
#include <QTableWidgetItem>//表格
#include "qcustomplot.h"
#include <QTreeWidget>
#include "QStringList"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("TabWidget"));//设置标题

    ui->tabWidget->setTabPosition(QTabWidget::North);//设置选项卡的方位东南西北，默认在上方
    //ui->tabWidget->setTabShape(QTabWidget::Triangular);//设置选项卡的形状
    ui->tabWidget->setTabIcon(0,QIcon("E:\\Qt_Project\\QTabWidget\\1.ico"));//设置选项卡图标
    ui->tabWidget->setTabIcon(1,QIcon("E:\\Qt_Project\\QTabWidget\\2.ico"));//设置选项卡图标
    ui->tabWidget->setTabIcon(2,QIcon("E:\\Qt_Project\\QTabWidget\\3.ico"));//设置选项卡图标
    ui->tabWidget->setTabIcon(3,QIcon("E:\\Qt_Project\\QTabWidget\\4.ico"));//设置选项卡图标
    ui->tabWidget->setTabIcon(4,QIcon("E:\\Qt_Project\\QTabWidget\\5.ico"));//设置选项卡图标
    ui->tabWidget->setIconSize(QSize(50,25));//设置图标的大小(选项卡的大小也会改变)
    ui->tabWidget->setMovable(true);
    ui->tabWidget->setTabsClosable(true);//在选项卡上添加关闭按钮
    qDebug()<<"第一个选项卡名称："<<ui->tabWidget->tabText(0);//获取选项卡名称
    qDebug()<<"iconSize:"<<ui->tabWidget->iconSize();//获取icon的尺寸
    //ui->tabWidget->clear();//清空选项卡

    /*
     * 运动选项卡
    */
    ui->tableWidgetSports->setColumnCount(6);//设置列数
    ui->tableWidgetSports->setRowCount(10);//设置行数
    ui->tableWidgetSports->setWindowTitle("QTableWidget");
    QStringList m_Header;
    m_Header<<QString("田径")<<QString("篮球")<<QString("足球")<<QString("乒乓球")<<QString("羽毛球")<<QString("游泳");
    ui->tableWidgetSports->setHorizontalHeaderLabels(m_Header);//添加横向表头
    ui->tableWidgetSports->verticalHeader()->setVisible(true); //纵向表头可视化
    ui->tableWidgetSports->horizontalHeader()->setVisible(true);//横向表头可视化
    //ui->tableWidget->setShowGrid(false);//隐藏栅格
    ui->tableWidgetSports->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置编辑方式：禁止编辑表格
    ui->tableWidgetSports->setSelectionBehavior(QAbstractItemView::SelectRows);//设置表格选择方式：设置表格为整行选中
    //ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectColumns);//设置表格选择方式：设置表格为整列选中
    ui->tableWidgetSports->setSelectionMode(QAbstractItemView::SingleSelection);//选择目标方式
    ui->tableWidgetSports->setStyleSheet("selection-background-color:pink");//设置选中颜色：粉色

    for(int rows=0;rows<10;rows++)
    {
        for(int columns=0;columns<6;columns++)
        {
            if(columns==0)
            {
                ui->tableWidgetSports->setItem(rows,columns,new QTableWidgetItem("刘翔"));
            }
            else if(columns==1)
            {
                ui->tableWidgetSports->setItem(rows,columns,new QTableWidgetItem("姚明"));
            }
            else if(columns==2)
            {
                ui->tableWidgetSports->setItem(rows,columns,new QTableWidgetItem("C罗"));
            }
            else  if(columns==3)
            {
                ui->tableWidgetSports->setItem(rows,columns,new QTableWidgetItem("马林"));
            }
            else if(columns==4)
            {
                ui->tableWidgetSports->setItem(rows,columns,new QTableWidgetItem("林丹"));
            }
            else if(columns==5)
            {
                ui->tableWidgetSports->setItem(rows,columns,new QTableWidgetItem("孙杨"));
            }
        }
    }
    for(int rows=0;rows<10;rows++)
    {
        for(int columns=0;columns<6;columns++)
        {
            ui->tableWidgetSports->setColumnWidth(columns,125);
            ui->tableWidgetSports->setRowHeight(rows,30);
            ui->tableWidgetSports->item(rows,columns)->setTextAlignment(Qt::AlignCenter);//居中显示
            ui->tableWidgetSports->item(rows,columns)->setBackgroundColor(QColor(85,170,255));//设置前景颜色
            ui->tableWidgetSports->item(rows,columns)->setTextColor(QColor(0,0,0));//设置文本颜色
            ui->tableWidgetSports->item(rows,columns)->setFont(QFont("Helvetica"));//设置字体为黑体
        }
    }

    //音乐选项卡
    ui->qCustomPlotMusic->plotLayout()->insertRow(0);
    ui->qCustomPlotMusic->plotLayout()->addElement(0, 0, new QCPTextElement(ui->qCustomPlotMusic, "网易云音乐播放和评论统计图", QFont("微软雅黑",12, QFont::Bold)));


    // set dark background gradient设置暗背景梯度:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(200, 150, 220));
    gradient.setColorAt(0.56, QColor(200, 150, 200));
    gradient.setColorAt(1, QColor(220, 150, 200));
    ui->qCustomPlotMusic->setBackground(QBrush(gradient));

    // create empty bar chart objects创建三个空的条形图对象:
    QCPBars *LoveTime = new QCPBars(ui->qCustomPlotMusic->xAxis, ui->qCustomPlotMusic->yAxis);  //播放
    QCPBars *LoveTimes = new QCPBars(ui->qCustomPlotMusic->xAxis, ui->qCustomPlotMusic->yAxis2);//评论
    //将LatencyTime和ErrorTimes并排显示
    QCPBarsGroup *group = new QCPBarsGroup(ui->qCustomPlotMusic);
    LoveTime->setBarsGroup(group);
    LoveTimes->setBarsGroup(group);
    //设置抗锯齿
    LoveTime->setAntialiased(false); // gives more crisp, pixel aligned bar borders:提供更清晰，像素对齐的条形边框
    LoveTimes->setAntialiased(false);
    //设置叠加差距
    //LatencyTime->setStackingGap(1);
    //ErrorTimes->setStackingGap(1);
    //fossil->setStackingGap(1);
    // set names and colors设置名称和颜色:
    LoveTimes->setWidth(0.3);//设置宽度
    //ErrorTimes->setWidthType("wtPlotCoords");//wtAbsolute:wtAxisRectRatio:wtPlotCoords设置宽度
    LoveTimes->setName("评论");
    LoveTimes->setPen(QPen(QColor(250, 170, 20).lighter(150)));
    LoveTimes->setBrush(QColor(250, 170, 20));
    LoveTime->setWidth(0.3);//设置宽度
    //LatencyTime->setWidthType("wtPlotCoords");//wtAbsolute:wtAxisRectRatio:wtPlotCoords设置宽度
    LoveTime->setName("播放");
    LoveTime->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    LoveTime->setBrush(QColor(0, 168, 140));
    // stack bars on top of each other把一个Bar叠加在另外一个Bar上面
    //ErrorTimes->moveAbove(fossil);
    //LatencyTime->moveAbove(ErrorTimes);

    //绘制xAxis
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7<<8;
    labels << "盗将行" << "流浪" << "倒数" << "沙漠骆驼" << "爱的故事" << "成都" << "38度6"<<"卡路里";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->qCustomPlotMusic->xAxis->setTicker(textTicker);//设置刻度标记CH
    ui->qCustomPlotMusic->xAxis->setTickLabelRotation(60);//设置刻度标签旋转
    ui->qCustomPlotMusic->xAxis->setSubTicks(false);//设置是否显示子刻度线
    ui->qCustomPlotMusic->xAxis->setTickLength(0, 4);//设置标记的长度
    ui->qCustomPlotMusic->xAxis->setRange(0, 9);//设置范围
    ui->qCustomPlotMusic->xAxis->setBasePen(QPen(Qt::white));//设置轴基线颜色
    ui->qCustomPlotMusic->xAxis->setTickPen(QPen(Qt::white));//设置刻度颜色
    ui->qCustomPlotMusic->xAxis->grid()->setVisible(true);//网格可视
    ui->qCustomPlotMusic->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));//网格虚线
    ui->qCustomPlotMusic->xAxis->setTickLabelColor(Qt::white);//设置刻度标签颜色
    ui->qCustomPlotMusic->xAxis->setLabelColor(Qt::white);//设置轴标签的颜色

    // 绘制yAxis:
    ui->qCustomPlotMusic->yAxis->setRange(0, 1000000);//设置轴范围的下限和上限
    ui->qCustomPlotMusic->yAxis->setPadding(5); // 设置轴的填充a bit more space to the left border：在左边边界多留一点空间
    ui->qCustomPlotMusic->yAxis->setLabel("播放次数(次)");
    ui->qCustomPlotMusic->yAxis->setBasePen(QPen(Qt::white));//设置轴基线颜色
    ui->qCustomPlotMusic->yAxis->setTickPen(QPen(Qt::white));//设置刻度线颜色
    ui->qCustomPlotMusic->yAxis->setSubTickPen(QPen(Qt::white));//设置子刻度线颜色
    ui->qCustomPlotMusic->yAxis->grid()->setSubGridVisible(true);//设置子网格可视
    ui->qCustomPlotMusic->yAxis->setTickLabelColor(Qt::white);//设置刻度标签颜色
    ui->qCustomPlotMusic->yAxis->setLabelColor(Qt::white);//设置轴标签的颜色
    ui->qCustomPlotMusic->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));//设置网格颜色和线型,网格实线
    ui->qCustomPlotMusic->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));//设置子网格颜色和线型,网格虚线

    // 绘制yAxis2:
    ui->qCustomPlotMusic->yAxis2->setRange(0, 10000);//设置轴范围的下限和上限
    ui->qCustomPlotMusic->yAxis2->setPadding(5); // 设置轴的填充a bit more space to the left border：在左边边界多留一点空间
    ui->qCustomPlotMusic->yAxis2->setLabel("评论次数(次)");
    ui->qCustomPlotMusic->yAxis2->setBasePen(QPen(Qt::white));//设置轴基线颜色
    ui->qCustomPlotMusic->yAxis2->setTickPen(QPen(Qt::white));//设置刻度线颜色
    ui->qCustomPlotMusic->yAxis2->setSubTickPen(QPen(Qt::white));//设置子刻度线颜色
    ui->qCustomPlotMusic->yAxis2->grid()->setSubGridVisible(true);//设置子网格可视
    ui->qCustomPlotMusic->yAxis2->setTickLabelColor(Qt::white);//设置刻度标签颜色
    ui->qCustomPlotMusic->yAxis2->setLabelColor(Qt::white);//设置轴标签的颜色
    ui->qCustomPlotMusic->yAxis2->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));//设置网格颜色和线型，网格实线
    ui->qCustomPlotMusic->yAxis2->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));//设置子网格颜色和线型，网格虚线
    ui->qCustomPlotMusic->yAxis2->setVisible(true);//默认为不可视,需要设置为可视
    // Add data添加数据:
    QVector<double> LoveTimesData, LoveTimeData;
    LoveTimesData << 1553 << 2454<< 7676 << 2434 << 5641 << 9655 << 3556 << 6899;
    LoveTimeData   << 121334 << 65657 << 534343 << 65778 << 134356 << 978788 << 44345 << 9545;
    LoveTimes->setData(ticks, LoveTimesData);//将容器内数据添加到对应刻度的点上，数量应相同
    LoveTime->setData(ticks, LoveTimeData);

    // setup legend设置说明图例:
    ui->qCustomPlotMusic->legend->setVisible(true);//说明图例可视
    ui->qCustomPlotMusic->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignLeft);//AlignTop:顶端对齐，AlignHCenter:中心对齐
    ui->qCustomPlotMusic->legend->setBrush(QColor(255, 255, 255, 100));
    ui->qCustomPlotMusic->legend->setBorderPen(Qt::NoPen);//设置边框颜色
    QFont legendFont = font();//获取字体
    legendFont.setPointSize(10);//设置字体大小，必须大于0
    //legendFont.setStyleName(Qt::微软雅黑);

    ui->qCustomPlotMusic->legend->setFont(legendFont);//设置默认字体
    //ui->qCustomPlotMusic->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);//客户交互，界面可以移动

    //软件选项卡
    ui->radioButton_6->setChecked(true);//选中网易公开课
    ui->checkBox->setChecked(true);//选中网易公开课


    //ui->treeWidgetDigital->clear();
    ui->treeWidgetDigital->setColumnCount(1); //设置列数
    ui->treeWidgetDigital->setHeaderLabels(QStringList(tr("数码产品")));//设置头的标题
    ui->treeWidgetDigital->setHeaderHidden(false);
    QTreeWidgetItem *items1 = new QTreeWidgetItem(ui->treeWidgetDigital,
                           QStringList(QString("手机")));
    items1->setIcon(0,QIcon("E:\\Qt_Project\\QTabWidget\\1.ico"));
    QTreeWidgetItem *items11 = new QTreeWidgetItem(items1,
                           QStringList(QString("苹果")));
    items11->setIcon(0,QIcon("E:\\Qt_Project\\QTabWidget\\2.ico"));
    QTreeWidgetItem *items12 = new QTreeWidgetItem(items1,
                           QStringList(QString("华为")));
    items12->setIcon(0,QIcon("E:\\Qt_Project\\QTabWidget\\3.ico"));
    QTreeWidgetItem *items13 = new QTreeWidgetItem(items1,
                           QStringList(QString("小米")));
    items13->setIcon(0,QIcon("E:\\Qt_Project\\QTabWidget\\4.ico"));

    QTreeWidgetItem *items2 = new QTreeWidgetItem(ui->treeWidgetDigital,
                           QStringList(QString("笔记本电脑")));
    items2->setIcon(0,QIcon("E:\\Qt_Project\\QTabWidget\\5.ico"));
    QTreeWidgetItem *items21 = new QTreeWidgetItem(items2,
                           QStringList(QString("Dell")));
    items21->setIcon(0,QIcon("E:\\Qt_Project\\QTabWidget\\6.ico"));
    QTreeWidgetItem *items22 = new QTreeWidgetItem(items2,
                           QStringList(QString("华硕")));
    items22->setIcon(0,QIcon("E:\\Qt_Project\\QTabWidget\\7.ico"));

    QTreeWidgetItem *items3 = new QTreeWidgetItem(ui->treeWidgetDigital,
                           QStringList(QString("平板电脑")));
    items3->setIcon(0,QIcon("E:\\Qt_Project\\QTabWidget\\8.ico"));

    QList<QTreeWidgetItem *> rootList;
    QTreeWidgetItem *items4 = new QTreeWidgetItem;   //添加第一个父节点
    items4->setText(0,tr("数码相机"));
    items4->setIcon(0,QIcon("E:\\Qt_Project\\QTabWidget\\9.ico"));
    rootList.append(items4);
    QTreeWidgetItem *items41= new QTreeWidgetItem(items4,QStringList(QString("索尼"))); //添加子节点
    items41->setIcon(0,QIcon("E:\\Qt_Project\\QTabWidget\\10.ico"));
    items4->addChild(items41);
    ui->treeWidgetDigital->insertTopLevelItems(0,rootList);  //将结点插入部件中
    ui->treeWidgetDigital->expandAll(); //结点全部展开
    //ui->items1->setText(0, "手机");
    //ui->treeWidgetDigital->addTopLevelItem(new QTreeWidgetItem((QTreeWidget*)0));
    //ui->treeWidgetDigital->addTopLevelItem(tr("笔记本电脑"));

    //语言选项卡
    ui->listWidgetLanguage->addItem(tr("中文"));
    ui->listWidgetLanguage->addItem(tr("英语"));
    ui->listWidgetLanguage->addItem(tr("法语"));
    ui->listWidgetLanguage->addItem(tr("德语"));
    ui->listWidgetLanguage->addItem(tr("日语"));
    ui->listWidgetLanguage->addItem(tr("韩语"));
    ui->listWidgetLanguage->addItem(tr("俄语"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
