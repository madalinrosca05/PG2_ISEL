#ifndef PROCESSFILE_H
#define PROCESSFILE_H

int processFile(const char *filename, int (*action)(const char *line, void *context), void *context);

#endif