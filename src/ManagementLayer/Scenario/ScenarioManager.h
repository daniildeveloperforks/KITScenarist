#ifndef SCENARIOMANAGER_H
#define SCENARIOMANAGER_H

#include <QObject>

class QComboBox;
class QLabel;

namespace BusinessLogic {
	class ScenarioDocument;
}

namespace ManagementLayer
{
	class ScenarioNavigatorManager;
	class ScenarioTextEditManager;


	/**
	 * @brief Управляющий сценарием
	 */
	class ScenarioManager : public QObject
	{
		Q_OBJECT

	public:
		explicit ScenarioManager(QObject* _parent, QWidget* _parentWidget);

		QWidget* view() const;

		/**
		 * @brief Загрузить данные текущего проекта
		 */
		void loadCurrentProject();

		/**
		 * @brief Сохранить данные текущего проекта
		 */
		void saveCurrentProject();

	private slots:
		/**
		 * @brief Обновить хронометраж
		 */
		void aboutUpdateDuration(int _cursorPosition);

	private:
		/**
		 * @brief При запуске инициилизировать пустыми данными
		 */
		void initData();

		/**
		 * @brief Настроить представление
		 */
		void initView();

		/**
		 * @brief Настроить соединения
		 */
		void initConnections();

	private:
		/**
		 * @brief Представление сценария
		 */
		QWidget* m_view;

		/**
		 * @brief Документ сценария
		 */
		BusinessLogic::ScenarioDocument* m_document;

		/**
		 * @brief Управляющий навигацией по сценарию
		 */
		ScenarioNavigatorManager* m_navigatorManager;

		/**
		 * @brief Управляющий редактированием сценария
		 */
		ScenarioTextEditManager* m_textEditManager;
	};
}

#endif // SCENARIOMANAGER_H