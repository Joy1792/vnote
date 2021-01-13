#ifndef EXPORTER_H
#define EXPORTER_H

#include <QObject>
#include <QStringList>

#include "exportdata.h"

namespace vnotex
{
    class Notebook;
    class Node;
    class Buffer;
    class File;

    class Exporter : public QObject
    {
        Q_OBJECT
    public:
        // We need the QWidget as parent.
        explicit Exporter(QWidget *p_parent);

        // Return exported output file.
        QString doExport(const ExportOption &p_option, Buffer *p_buffer);

        // Return exported output files.
        QStringList doExport(const ExportOption &p_option, Node *p_folder);

        QStringList doExport(const ExportOption &p_option, Notebook *p_notebook);

    private:
        QStringList doExport(const ExportOption &p_option, const QString &p_outputDir, Node *p_folder);

        QString doExport(const ExportOption &p_option, const QString &p_outputDir, const File *p_file);

        QString doExportMarkdown(const ExportOption &p_option, const QString &p_outputDir, const File *p_file);

        QString doExportHtml(const ExportOption &p_option, const QString &p_outputDir, const File *p_file);

        void exportAttachments(Node *p_node,
                               const QString &p_srcFilePath,
                               const QString &p_outputFolder,
                               const QString &p_destFilePath);

    signals:
        void progressUpdated(int p_val, int p_maximum);

        void logRequested(const QString &p_log);
    };
}

#endif // EXPORTER_H
