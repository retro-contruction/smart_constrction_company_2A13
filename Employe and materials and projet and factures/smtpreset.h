#ifndef SMTPRESET_H
#define SMTPRESET_H


        #include <QTcpSocket>
        #include <QString>
        #include <QTextStream>
        #include <QDebug>
        #include <QMessageBox>

        class Smtpreset : public QObject
        {
            Q_OBJECT


        public:
            Smtpreset( const QString &from, const QString &to,
            const QString &subject, const QString &body );
            ~Smtpreset();

        signals:
            void status( const QString &);

        private slots:
            void stateChanged(QTcpSocket::SocketState socketState);
            void errorReceived(QTcpSocket::SocketError socketError);
            void disconnected();
            void connected();
            void readyRead();

        private:
            QString message;
            QTextStream *t;
            QTcpSocket *socket;
            QString from;
            QString rcpt;
            QString response;
            enum states{Rcpt,Mail,Data,Init,Body,Quit,Close};
            int state;

        };

#endif // SMTPRESET_H
