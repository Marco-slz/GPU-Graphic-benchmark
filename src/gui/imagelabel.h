// QLabel subclass that scales a supplied image to fit its current contents.
#pragma once
#include <QPixmap>
#include <QtWidgets>
class ImageLabel : public QLabel
{
  public:
    using QLabel::QLabel;

    // Store a new source image and immediately render it at the current size.
    void setImagePixmap(const QPixmap &pixmap)
    {
        m_image = pixmap;
        updateImage();
    }

  private:
    QPixmap m_image;
    // Recompute the displayed image whenever the label's geometry changes.
    void resizeEvent(QResizeEvent *event) override
    {
        QLabel::resizeEvent(event);
        updateImage();
    }
    // Preserve the source aspect ratio while smoothly fitting the label.
    void updateImage()
    {
        if (!m_image.isNull())
        {
            setPixmap(m_image.scaled(contentsRect().size(), Qt::KeepAspectRatio,
                                     Qt::SmoothTransformation));
        }
    }
};
