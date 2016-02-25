#ifndef UTILS_H__
#define UTILS_H__

/// Compare two keys order.
/// return -1 if firstKey < secondKey;
///         0 if firstKey = secondKey;
///         1 if firstKey > secondKey.
typedef int (*cmp_func)(const void *firstKey, const void *secondKey);

/// Compare two keys for equality.
/// return 1 if firstKey equal  secondKey;
///        0 if firstKey not equal secondKey.
typedef int (*eq_func)(const void *firstKey, const void *secondKey);

/// Release data.
typedef void (*destructor_func)(void *data);

#endif // UTILS_H__
