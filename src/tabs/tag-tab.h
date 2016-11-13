#ifndef TAG_TAB_H
#define TAG_TAB_H

#include <QWidget>
#include <QMap>
#include <QCalendarWidget>
#include "ui/textedit.h"
#include "search-tab.h"
#include "models/page.h"
#include "mainwindow.h"
#include "downloader/downloader.h"



namespace Ui
{
	class tagTab;
}



class mainWindow;

class tagTab : public searchTab
{
	Q_OBJECT

	public:
		explicit tagTab(int id, QMap<QString, Site*> *sites, Profile *profile, mainWindow *parent);
		~tagTab();
		Ui::tagTab *ui;
		QString tags();
		QString results();
		int imagesPerPage();
		int columns();
		QString postFilter();
		QList<Site*> loadSites() override;

	public slots:
		// Search
		void firstPage();
		void previousPage();
		void nextPage();
		void lastPage();
		// Zooms
		void setTags(QString);
		// Loading
		void load();
		bool validateImage(QSharedPointer<Image> img);
		// Batch
		void getPage();
		void getAll();
		// Others
		void closeEvent(QCloseEvent*);
		void on_buttonSearch_clicked();
		void setImagesPerPage(int ipp);
		void setColumns(int columns);
		void setPostFilter(QString postfilter);
		void focusSearch();

	private:
		int				m_id;
		TextEdit		*m_search;
		QCalendarWidget	*m_calendar;
		QString			m_link;
		bool			m_sized;
		Downloader		*m_downloader;
};

#endif // TAG_TAB_H
