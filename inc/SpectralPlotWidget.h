#ifndef SPECTRALPLOTWIDGET_H
#define SPECTRALPLOTWIDGET_H

#include <QWidget>
#include <vector>
#include <QColor>

class SpectralPlotWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SpectralPlotWidget(QWidget *parent = nullptr);

    // 添加光谱数据
    void addSpectrumData(const std::vector<float> &spectrumData, const QPoint &pixelPosition);

    // 清除所有光谱数据
    void clearSpectra();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    struct SpectrumData {
        std::vector<float> data;
        QColor color;
        QPoint pixelPosition;
    };

    std::vector<SpectrumData> spectra;  // 存储多条光谱数据
    std::vector<QColor> colorPalette;   // 颜色调色板
    int colorIndex;                     // 当前使用的颜色索引

    // 初始化颜色调色板
    void initColorPalette();

    // 获取下一个颜色
    QColor getNextColor();
};

#endif // SPECTRALPLOTWIDGET_H
