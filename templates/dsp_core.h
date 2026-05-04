#ifndef DSP_CORE_H
#define DSP_CORE_H

#include <stdint.h>

// 硬件相关宏定义，用于生理信号传感器的量化
#define Q_FACTOR 8
#define SENSOR_ARRAY_SIZE 5

// 采用 stdint.h 规范，确保跨平台内存分配的安全性
typedef struct {
    uint16_t sensor_id;
    int32_t raw_signal;
    int32_t filtered_signal;
} PhysiologicSensorData;

// 自适应滤波处理函数声明
void apply_adaptive_wiener_filter(PhysiologicSensorData* data_array, uint16_t length);

#endif // DSP_CORE_H
