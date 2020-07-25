#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QDebug>
#include <QSqlError>
#include <QDateTime>

class PatientModel : public QSqlQueryModel
{
public:
    PatientModel()
    {
        this->setQuery("select * from patient");
    }

    //配置单元格标志
    Qt::ItemFlags flags(const QModelIndex &index) const override
    {
        //qDebug()<<index.column()<<index.row();
        Qt::ItemFlags flags = QSqlQueryModel::flags(index);

        if(index.column() == 1 || index.column() == 2)
        {
            flags |= Qt::ItemIsEditable;    //等价于flags = flags | Qt::ItemIsEditable;表示按位执行或运算
        }
        return flags;
    }

    bool setName(int id, QString name)
    {
        //todo
        bool ok;
        QSqlQuery query;
        query.prepare("update kk.patient set name = :name where id = :id");
        query.bindValue(":name", name);
        query.bindValue(":id", id);
        ok = query.exec();
        qDebug()<<id<<name;
        if(!ok)
        {
            qDebug()<<"setname error:"<<query.lastError();
        }
        return true;
    }

    bool setSex(int id, QString sex)
    {
        //todo
        bool ok;
        QSqlQuery query;
        query.prepare("update kk.patient set sex = :sex where id = :id");
        query.bindValue(":sex", sex);
        query.bindValue(":id", id);
        ok = query.exec();
        //OK = queryRefresh.exec();
        qDebug()<<id<<sex;
        if(!ok)
        {
            qDebug()<<"setSex error:"<<query.lastError();
        }
        return true;
    }

    bool setData(const QModelIndex &index, const QVariant &value, int)
    {
        if (index.column() < 1 || index.column() > 2)
        {
            return false;
        }

        //获取当前行的第0列内容
        QModelIndex primaryKeyIndex = QSqlQueryModel::index(index.row(), 0);

        int id = this->data(primaryKeyIndex).toInt();

        bool OK;
        if(index.column() == 1)
        {
            //修改病人姓名
            OK = this->setName(id, value.toString());
        }
        else if(index.column() == 2)
        {
            //修改病人性别
            OK = this->setSex(id, value.toString());
        }

        if(OK)
        {
            //this->setQuery("select * from patient");
            this->setQuery("select * from patient left join device_patient on patient.id = device_patient.patient_id left join device on device.dev_id = device_patient.dev_id");
        }

        return OK;

    }
};

int main(int argc, char *argv[])
{

    bool OK;
    QApplication a(argc, argv);

    //创建view
    QTableView *view = new QTableView();

    //创建模型
    QSqlQueryModel model;

    //创建病人view
    QTableView *patientView = new QTableView();

    //创建病人模型
    PatientModel patients;

    QTableView *patientsDevView = new QTableView();

    PatientModel patientsDev;

    //加载驱动
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    //配置服务器
    db.setHostName("localhost");

    //数据库名字
    db.setDatabaseName("kk");

    //用户名密码
    db.setUserName("wozizhi");
    db.setPassword("123456");

    //打开连接
    //要判断连接是否成功
    bool db0k = db.open();
    if(db0k)
    {
        qDebug()<<"连接成功";
    }
    else
    {
        qDebug()<<"连接失败";
        qDebug()<<db.lastError();
        return a.exec();
    }

    //给表添加1条记录

    //QSqlQuery query(db);
    if(db0k)
    {
        bool queryOK;
        //QSqlQuery负责执行SQL语句
        QSqlQuery query;
        //添加一行
//        queryOK = query.exec("insert into kk.doctor (uid, name, mobile) values ('doctor2', '张无忌', 13987654322);");
//        if(!queryOK)
//        {
//            qDebug()<<query.lastError();
//        }
        //数据查询
        queryOK = query.exec("select * from kk.doctor where uid = 'doctor2'");
        qDebug()<<query.size();
        if (query.size() > 0)
        {
            while(query.next())
                qDebug()<<query.value("uid").toString()<<query.value("name").toString()<<query.value("mobile").toLongLong();
        }

        //prepare方法查询
        query.prepare("select * from kk.doctor where uid = :id");
        QString uid = "doctor1";
        query.bindValue(":id", uid);
        query.exec();
        if (query.size() > 0)
        {
            while(query.next())
            {
                qDebug()<<query.value("uid").toString()<<query.value("name").toString()<<query.value("mobile").toLongLong();
            }
        }



//模拟终端设备给数据库上传波形数据
        //查询device表
        QSqlQuery queryDev;
        queryDev.prepare("select * from kk.device where serial = :serial");
        queryDev.bindValue(":serial", "DEV-002");
        OK = queryDev.exec();
        int dev_id = 0;
        if (!OK)
        {
            qDebug()<<"设备ID查询错误"<<queryDev.lastError();
        }
        else
        {
            if(queryDev.size() > 0 && queryDev.next())
            {

                dev_id = queryDev.value("dev_id").toInt();
                qDebug()<<"dev_id = "<<dev_id;
            }
            else
            {
                //增加当前设备
                OK = queryDev.exec("insert into kk.device (serial) values ('DEV-002')");
                if(!OK)
                {
                    qDebug()<<"增加设备错误"<<queryDev.lastError();
                }
                else
                {
                    qDebug()<<"增加设备成功";
                }
            }
        }

        //波形数据上传
        if(dev_id != 0)
        {
            QSqlQuery queryWave;
            bool queryWaveOK;
            short samples[10] = {2040,2041,2042,2043,2044,2045,2046,2047,2048,2049};
            QByteArray waves((char*)samples, sizeof(samples));
            queryWave.prepare("insert into kk.ecg_sample (dev_id, value, time) values(:dev_id, :array, :time)");
            queryWave.bindValue("dev_id", dev_id);
            queryWave.bindValue(":array", waves);
            queryWave.bindValue(":time", QDateTime::currentDateTime());
            queryWaveOK = queryWave.exec();
            if(!queryWaveOK)
            {
                qDebug()<<"wave update:"<<queryWave.lastError();
            }
         }
         else
         {
            qDebug()<<"wave update error no dev_id";
         }


        //更新refresh
        if(dev_id != 0)
        {
            QSqlQuery queryRefresh;
            queryRefresh.prepare("update kk.device set refresh = now() where dev_id = :dev_id");
            queryRefresh.bindValue(":dev_id", dev_id);
            OK = queryRefresh.exec();
            if(OK)
            {
                qDebug()<<"设备在线状态已更新";
            }
            else
            {
                qDebug()<<"设备在线更新失败"<<queryRefresh.lastError();
            }
        }


//工作站查看设备列表
        //获取数据
        model.setQuery("SELECT dev_id, serial, now()-refresh <20 AS online FROM device");
        //配置表格显示控件的模型
        view->setModel(&model);
        view->show();

        //显示病人列表
        patients.setQuery("select * from patient");
        patientView->setModel(&patients);
        patientView->show();

        //显示病人设备关联表
         //patientsDev.setQuery("select * from patient, device, device_patient where patient.id = device_patient.patient_id and device.dev_id = device_patient.dev_id");
         patientsDev.setQuery("select * from patient left join device_patient on patient.id = device_patient.dev_id left join device on device.dev_id = device_patient.dev_id");
         patientsDevView->setModel(&patientsDev);
         patientsDevView->show();

    }//db0k = True

    return a.exec();
}
