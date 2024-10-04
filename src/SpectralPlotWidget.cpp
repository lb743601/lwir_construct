#include "SpectralPlotWidget.h"
#include <QPainter>
#include <algorithm>

SpectralPlotWidget::SpectralPlotWidget(QWidget *parent)
    : QWidget(parent),
      colorIndex(0)
{
    initColorPalette();
}

void SpectralPlotWidget::initColorPalette()
{
    // 初始化颜色调色板，可以根据需要添加更多颜色
    colorPalette = {
        Qt::blue,
        Qt::red,
        Qt::green,
        Qt::magenta,
        Qt::cyan,
        Qt::yellow,
        Qt::darkBlue,
        Qt::darkRed,
        Qt::darkGreen,
        Qt::darkMagenta,
        Qt::darkCyan,
        Qt::darkYellow
    };
}

QColor SpectralPlotWidget::getNextColor()
{
    QColor color = colorPalette[colorIndex % colorPalette.size()];
    colorIndex++;
    return color;
}

void SpectralPlotWidget::addSpectrumData(const std::vector<float> &spectrumData, const QPoint &pixelPosition)
{
    SpectrumData data;
    data.data = spectrumData;
    data.color = getNextColor();
    data.pixelPosition = pixelPosition;

    spectra.push_back(data);
    update();  // 触发重绘
}

void SpectralPlotWidget::clearSpectra()
{
    spectra.clear();
    colorIndex = 0;
    update();
}

void SpectralPlotWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    if (spectra.empty()) {
        return;  // 如果没有光谱数据，则不绘制
    }

    QPainter painter(this);

    // 清除背景
    painter.fillRect(rect(), Qt::white);

    // 设置绘图参数
    painter.setRenderHint(QPainter::Antialiasing, true);

    // 获取绘图区域尺寸，留出边距用于坐标轴和图例
    QRect drawRect = rect().adjusted(50, 20, -80, -50);  // 右边留更多空间用于图例

    // 找到所有光谱数据的最大值和最小值，用于归一化
    float minValue = std::numeric_limits<float>::max();
    float maxValue = std::numeric_limits<float>::lowest();

    for (const auto &spectrum : spectra) {
        auto [minIt, maxIt] = std::minmax_element(spectrum.data.begin(), spectrum.data.end());
        if (*minIt < minValue) minValue = *minIt;
        if (*maxIt > maxValue) maxValue = *maxIt;
    }

    // 防止除以零
    if (maxValue - minValue == 0) {
        maxValue += 1.0f;
    }

    // 绘制坐标轴
    painter.setPen(Qt::black);
    painter.drawLine(drawRect.bottomLeft(), drawRect.topLeft());     // Y轴
    painter.drawLine(drawRect.bottomLeft(), drawRect.bottomRight()); // X轴

    // 绘制坐标轴标签
    QFontMetrics fm = painter.fontMetrics();
    // Y轴标签
    QString yAxisLabel = "灰度值";
    int yAxisLabelWidth = fm.width(yAxisLabel);
    painter.drawText(drawRect.left() - yAxisLabelWidth / 2, drawRect.top() - 10, yAxisLabel);
    // X轴标签
    QString xAxisLabel = "波段数";
    int xAxisLabelWidth = fm.width(xAxisLabel);
    painter.drawText(drawRect.right() - xAxisLabelWidth / 2, drawRect.bottom() + 40, xAxisLabel);

    // 绘制X轴刻度和标签
    int numBands = spectra.front().data.size();
    int xTickInterval = numBands / 5;  // 显示5个刻度
    for (int i = 0; i < numBands; ++i) {
        float normalizedX = static_cast<float>(i) / (numBands - 1);
        int x = drawRect.left() + normalizedX * drawRect.width();

        // 绘制刻度线
        if (i % xTickInterval == 0 || i == numBands - 1) {
            painter.drawLine(x, drawRect.bottom(), x, drawRect.bottom() + 5);

            // 绘制刻度标签
            QString label = QString::number(i + 1);
            int labelWidth = fm.width(label);
            painter.drawText(x - labelWidth / 2, drawRect.bottom() + 20, label);
        }
    }

    // 绘制Y轴刻度和标签
    int numYTicks = 5;
    for (int i = 0; i <= numYTicks; ++i) {
        float normalizedY = static_cast<float>(i) / numYTicks;
        int y = drawRect.bottom() - normalizedY * drawRect.height();
        painter.drawLine(drawRect.left() - 5, y, drawRect.left(), y);

        float value = minValue + normalizedY * (maxValue - minValue);
        QString label = QString::number(value, 'f', 1);
        int labelWidth = fm.width(label);
        painter.drawText(drawRect.left() - labelWidth - 10, y + fm.ascent() / 2, label);
    }

    // 绘制光谱曲线
    for (const auto &spectrum : spectra) {
        painter.setPen(QPen(spectrum.color, 2));

        int numPoints = spectrum.data.size();
        QPointF previousPoint;

        for (int i = 0; i < numPoints; ++i) {
            // 将光谱数据归一化到绘图区域
            float normalizedX = static_cast<float>(i) / (numPoints - 1);
            float normalizedY = (spectrum.data[i] - minValue) / (maxValue - minValue);

            int x = drawRect.left() + normalizedX * drawRect.width();
            int y = drawRect.bottom() - normalizedY * drawRect.height();

            QPointF currentPoint(x, y);

            if (i > 0) {
                painter.drawLine(previousPoint, currentPoint);
            }

            previousPoint = currentPoint;
        }
    }

    // 绘制图例
    int legendX = drawRect.right() + 10;
    int legendY = drawRect.top() + 20;
    int legendSpacing = 20;

    painter.setPen(Qt::black);
    painter.drawText(legendX, legendY - 10, "图例：");

    for (const auto &spectrum : spectra) {
        // 绘制颜色块
        painter.setPen(Qt::NoPen);
        painter.setBrush(spectrum.color);
        painter.drawRect(legendX, legendY - fm.ascent() + 5, 15, 15);

        // 绘制文本
        QString label = QString("(%1, %2)").arg(spectrum.pixelPosition.x()).arg(spectrum.pixelPosition.y());
        painter.setPen(Qt::black);
        painter.setBrush(Qt::NoBrush);
        painter.drawText(legendX + 20, legendY + 5, label);

        legendY += legendSpacing;
    }
}
