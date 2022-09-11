#ifndef TASK3_H
#define TASK3_H
#include <string>
#include <vector>

void* map3(void *varg);
void* reduce3(void *varg);
void* threadFIFO(void* arguments);
void writeFIFO(std::string name, std::vector<std::string> vector);
void read_FIFO (std::vector<std::string> &vector, std::string name);

#endif // TASK3_H