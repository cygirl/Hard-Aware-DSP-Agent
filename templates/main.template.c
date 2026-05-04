#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> // 引入 POSIX 线程，模拟并发数据采集
#include "dsp_core.h"

// 模拟传感器并发读取的线程函数
void* fetch_sensor_data(void* arg) {
    PhysiologicSensorData* data = (PhysiologicSensorData*)arg;
    // 模拟底层 I/O 读取
    data->raw_signal = (rand() % 1024) << Q_FACTOR; 
    pthread_exit(NULL);
}

int main() {
    PhysiologicSensorData array[SENSOR_ARRAY_SIZE];
    pthread_t threads[SENSOR_ARRAY_SIZE];

    // 多线程并发拉取传感器数据
    for (int i = 0; i < SENSOR_ARRAY_SIZE; i++) {
        array[i].sensor_id = i;
        pthread_create(&threads[i], NULL, fetch_sensor_data, (void*)&array[i]);
    }

    for (int i = 0; i < SENSOR_ARRAY_SIZE; i++) {
        pthread_join(threads[i], NULL);
    }

    // 调用算法逻辑（此处由 Agent 动态注入定点运算代码）
    apply_adaptive_wiener_filter(array, SENSOR_ARRAY_SIZE);

    return 0;
}
