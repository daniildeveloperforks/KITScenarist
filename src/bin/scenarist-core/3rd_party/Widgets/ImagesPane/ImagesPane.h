#ifndef IMAGESPANE_H
#define IMAGESPANE_H

#include <QScrollArea>

class AddImageButton;
class FlowLayout;
class ImagePreview;


/**
 * @brief Плитка изображений
 */
class ImagesPane : public QScrollArea
{
	Q_OBJECT

public:
	explicit ImagesPane(QWidget* _parent = 0);

	/**
	 * @brief Очистить
	 */
	void clear();

	/**
	 * @brief Добавить изображение
	 */
	void addImage(const QPixmap& _image);

	/**
	 * @brief Добавить изображение из указанного файла
	 */
	void addImageFromFile(const QString& _imagePath);

	/**
	 * @brief Получить список всех изображений
	 */
	QList<QPixmap> images() const;

signals:
	/**
	 * @brief Изображение добавлено
	 */
	void imageAdded(const QPixmap& _image, int sortOrder);

	/**
	 * @brief Изображение удалено
	 */
	void imageRemoved(const QPixmap& _image, int sortOrder);

private slots:
	/**
	 * @brief Показать изображение
	 */
	void showImage();

	/**
	 * @brief Удалить изображение
	 */
	void removeImage();

private:
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
	 * @brief Компоновщик
	 */
	FlowLayout* m_layout;

	/**
	 * @brief Кнопка добавления изображения
	 */
	AddImageButton* m_addImageButton;

	/**
	 * @brief Предпросмотрщик изображений
	 */
	ImagePreview* m_imagePreview;

	/**
	 * @brief Список изображений галереи
	 */
	QList<QPixmap> m_images;
};

#endif // IMAGESPANE_H
