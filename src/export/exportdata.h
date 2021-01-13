#ifndef EXPORTDATA_H
#define EXPORTDATA_H

#include <QSharedPointer>

class QPageLayout;

namespace vnotex
{
    enum class ExportSource
    {
        CurrentBuffer = 0,
        CurrentFolder,
        CurrentNotebook
    };

    enum class ExportFormat
    {
        Markdown = 0,
        HTML,
        PDF,
        Custom
    };

    struct ExportHtmlOption
    {
        bool m_embedStyles = true;

        bool m_completePage = true;

        bool m_embedImages = true;

        bool m_useMimeHtmlFormat = false;

        // Whether add outline panel.
        bool m_addOutlinePanel = true;
    };

    struct ExportPdfOption
    {
        QSharedPointer<QPageLayout> m_layout;

        bool m_useWkhtmltopdf = false;

        bool m_addTableOfContents = false;
    };

    struct ExportOption
    {
        ExportSource m_source = ExportSource::CurrentBuffer;

        ExportFormat m_targetFormat = ExportFormat::HTML;

        bool m_useTransparentBg = true;

        QString m_renderingStyleFile;

        QString m_syntaxHighlightStyleFile;

        QString m_outputDir;

        bool m_recursive = true;

        bool m_exportAttachments = true;

        QSharedPointer<ExportHtmlOption> m_htmlOption;
    };

    inline QString exportFormatString(ExportFormat p_format)
    {
        switch (p_format)
        {
        case ExportFormat::Markdown:
            return QStringLiteral("Markdown");

        case ExportFormat::HTML:
            return QStringLiteral("HTML");

        case ExportFormat::PDF:
            return QStringLiteral("PDF");

        case ExportFormat::Custom:
            return QStringLiteral("Custom");
        }

        return QStringLiteral("Unknown");
    }
}

#endif // EXPORTDATA_H
