#ifndef EXPORTDIALOG_H
#define EXPORTDIALOG_H

#include "scrolldialog.h"

#include <export/exportdata.h>

class QGroupBox;
class QPushButton;
class QComboBox;
class QCheckBox;
class QLineEdit;
class QProgressBar;
class QPlainTextEdit;

namespace vnotex
{
    class Notebook;
    class Node;
    class Buffer;
    class Exporter;

    class ExportDialog : public ScrollDialog
    {
        Q_OBJECT
    public:
        // Current notebook/folder/buffer.
        ExportDialog(Notebook *p_notebook,
                     Node *p_folder,
                     Buffer *p_buffer,
                     QWidget *p_parent = nullptr);

    protected:
        void rejectedButtonClicked() Q_DECL_OVERRIDE;

    private slots:
        void updateProgress(int p_val, int p_maximum);

        void appendLog(const QString &p_log);

    private:
        enum AdvancedSettings
        {
            General,
            HTML,
            Max
        };

        void setupUI();

        QGroupBox *setupSourceGroup(QWidget *p_parent);

        QGroupBox *setupTargetGroup(QWidget *p_parent);

        QGroupBox *setupAdvancedGroup(QWidget *p_parent);

        QWidget *setupGeneralAdvancedSettings(QWidget *p_parent);

        QWidget *getHtmlAdvancedSettings();

        void showAdvancedSettings(AdvancedSettings p_settings);

        void setupButtonBox();

        QString getOutputDir() const;

        void initOptions();

        void restoreFields(const ExportOption &p_option);

        void saveFields(ExportOption &p_option);

        void restoreFields(const ExportHtmlOption &p_option);

        void saveFields(ExportHtmlOption &p_option);

        void startExport();

        void updateUIOnExport();

        // Return exported files count.
        int doExport(ExportOption p_option);

        Exporter *getExporter();

        QString getDefaultOutputDir() const;

        // Managed by QObject.
        Exporter *m_exporter = nullptr;

        Notebook *m_notebook = nullptr;

        Node *m_folder = nullptr;

        Buffer *m_buffer = nullptr;

        // Last exported single file.
        QString m_exportedFile;

        bool m_exportOngoing = false;

        QPushButton *m_exportBtn = nullptr;

        QPushButton *m_openDirBtn = nullptr;

        QPushButton *m_copyContentBtn = nullptr;

        QComboBox *m_sourceComboBox = nullptr;

        QComboBox *m_targetFormatComboBox = nullptr;

        QCheckBox *m_transparentBgCheckBox = nullptr;

        QComboBox *m_renderingStyleComboBox = nullptr;

        QComboBox *m_syntaxHighlightStyleComboBox = nullptr;

        QLineEdit *m_outputDirLineEdit = nullptr;

        QProgressBar *m_progressBar = nullptr;

        QGroupBox *m_advancedGroupBox = nullptr;

        QVector<QWidget *> m_advancedSettings;

        // General settings.
        QCheckBox *m_recursiveCheckBox = nullptr;

        QCheckBox *m_exportAttachmentsCheckBox = nullptr;

        // HTML settings.
        QCheckBox *m_embedStylesCheckBox = nullptr;

        QCheckBox *m_embedImagesCheckBox = nullptr;

        QCheckBox *m_completePageCheckBox = nullptr;

        QCheckBox *m_useMimeHtmlFormatCheckBox = nullptr;

        QCheckBox *m_addOutlinePanelCheckBox = nullptr;

        static ExportOption s_option;
    };
}

#endif // EXPORTDIALOG_H
