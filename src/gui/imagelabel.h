#include <QtWidgets>
#include<QPixmap>
class ImageLabel : public QLabel{
    public:
        using QLabel::QLabel;
        void setImagePixmap(const QPixmap &pixmap){
            m_image = pixmap;
            updateImage();
        }

    private:
        QPixmap m_image;
        void resizeEvent(QResizeEvent *event) override{
            QLabel::resizeEvent(event);
            updateImage();
        }
        void updateImage(){
            if(!m_image.isNull()){
                setPixmap(m_image.scaled(
                    contentsRect().size(),
                    Qt::KeepAspectRatio,
                    Qt::SmoothTransformation
                ));
            }
        }
};  