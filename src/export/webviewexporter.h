#ifndef WEBVIEWEXPORTER_H
#define WEBVIEWEXPORTER_H

#include <QObject>

class QWidget;

namespace vnotex
{
    class WebViewExporter : public QObject
    {
        Q_OBJECT
    public:
        // We need QWidget as parent.
        explicit WebViewExporter(QWidget *p_parent);

        // Release resources after one batch of export.
        void clear();

    signals:
        void logRequested(const QString &p_log);
    };
}

#endif // WEBVIEWEXPORTER_H
