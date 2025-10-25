//#include <iostream>
//#include <cstring>  // 用于 memcpy
//#include <stdexcept> // 用于抛出异常（out_of_range）
//using namespace std;
//
//
//template <typename T>  // 模板类：支持任意数据类型（int、string、自定义类等）
//class Vector {
//public:
//    // ====================== 1. 构造与析构相关接口 ======================
//    // 1.1 默认构造：默认容量10
//    Vector(size_t init_capacity = 10)
//        : _capacity(init_capacity), _size(0) {
//        _data = new T[_capacity];  // 分配初始内存（默认10个元素空间）1
//    }
//
//    // 1.2 带初始值的构造：n个val
//    Vector(size_t n, const T& val)
//        : _capacity(n), _size(n) {
//        _data = new T[_capacity];
//        for (size_t i = 0; i < _size; ++i) {
//            _data[i] = val;  // 逐个初始化元素（支持自定义类型的赋值）
//        }
//    }
//
//    // 1.3 拷贝构造：深拷贝（避免浅拷贝导致的内存重复释放）
//    Vector(const Vector<T>& other)
//        : _capacity(other._capacity), _size(other._size) {
//        _data = new T[_capacity];
//        // 逐个拷贝元素（而非直接 memcpy，支持自定义类型的拷贝构造）
//        for (size_t i = 0; i < _size; ++i) {
//            _data[i] = other._data[i];
//        }
//    }
//
//    // 1.4 赋值运算符重载：深拷贝（处理自赋值）
//    Vector<T>& operator=(const Vector<T>& other) {
//        if (this != &other) {  // 避免自赋值（a = a）
//            // 1. 释放当前内存
//            delete[] _data;
//            // 2. 分配新内存并拷贝数据
//            _capacity = other._capacity;
//            _size = other._size;
//            _data = new T[_capacity];
//            for (size_t i = 0; i < _size; ++i) {
//                _data[i] = other._data[i];
//            }
//        }
//        return *this;  // 支持链式赋值（a = b = c）
//    }
//
//    // 1.5 析构函数：释放动态内存，避免内存泄漏
//    ~Vector() {
//        delete[] _data;
//        _data = nullptr;  // 置空指针，避免野指针
//        _capacity = 0;
//        _size = 0;
//    }
//
//
//    // ====================== 2. 容量管理接口 ======================
//    // 2.1 获取当前有效元素个数
//    size_t size() const {
//        return _size;
//    }
//
//    // 2.2 获取当前数组总容量
//    size_t capacity() const {
//        return _capacity;
//    }
//
//    // 2.3 判断数组是否为空（无有效元素）
//    bool empty() const {
//        return _size == 0;
//    }
//
//    // 2.4 预分配容量（避免频繁扩容，优化性能）
//    void reserve(size_t new_capacity) {
//        if (new_capacity <= _capacity) {
//            return;  // 新容量 ≤ 当前容量，无需操作
//        }
//        // 分配新内存并拷贝旧数据
//        T* new_data = new T[new_capacity];
//        for (size_t i = 0; i < _size; ++i) {
//            new_data[i] = _data[i];
//        }
//        // 释放旧内存，更新指针和容量
//        delete[] _data;
//        _data = new_data;
//        _capacity = new_capacity;
//    }
//
//    // 2.5 收缩容量至有效元素个数（减少内存浪费）
//    void shrink_to_fit() {
//        if (_size == _capacity) {
//            return;  // 容量已匹配，无需操作
//        }
//        // 分配与有效元素个数相等的新内存
//        T* new_data = new T[_size];
//        for (size_t i = 0; i < _size; ++i) {
//            new_data[i] = _data[i];
//        }
//        // 释放旧内存，更新指针和容量
//        delete[] _data;
//        _data = new_data;
//        _capacity = _size;
//    }
//
//
//    // ====================== 3. 元素访问接口 ======================
//    // 3.1 下标访问（非const版：支持修改元素）
//    T& operator[](size_t index) {
//        // 无边界校验（效率高，需用户确保索引合法）
//        return _data[index];
//    }
//
//    // 3.2 下标访问（const版：只读，不支持修改）
//    const T& operator[](size_t index) const {
//        return _data[index];
//    }
//
//    // 3.3 安全访问（带边界校验，越界抛出异常）
//    T& at(size_t index) {
//        if (index >= _size) {
//            throw out_of_range("Vector::at: index out of range");  // 抛出越界异常
//        }
//        return _data[index];
//    }
//
//    // 3.4 安全访问（const版）
//    const T& at(size_t index) const {
//        if (index >= _size) {
//            throw out_of_range("Vector::at: index out of range");
//        }
//        return _data[index];
//    }
//
//    // 3.5 获取第一个元素（非const版）
//    T& front() {
//        return at(0);  // 复用at()的边界校验
//    }
//
//    // 3.6 获取第一个元素（const版）
//    const T& front() const {
//        return at(0);
//    }
//
//    // 3.7 获取最后一个元素（非const版）
//    T& back() {
//        return at(_size - 1);  // 复用at()的边界校验
//    }
//
//    // 3.8 获取最后一个元素（const版）
//    const T& back() const {
//        return at(_size - 1);
//    }
//
//    // 3.9 获取底层数组指针（谨慎使用，避免越界）
//    T* data() {
//        return _data;
//    }
//
//    const T* data() const {
//        return _data;
//    }
//
//
//    // ====================== 4. 元素修改接口（增删） ======================
//    // 4.1 尾插元素（push_back）
//    void push_back(const T& val) {
//        if (_size == _capacity) {
//            // 容量不足：扩容（空数组扩为1，非空扩为2倍）
//            reserve(_capacity == 0 ? 1 : _capacity * 2);
//        }
//        _data[_size] = val;  // 赋值到末尾
//        ++_size;             // 有效元素数+1
//    }
//
//    // 4.2 尾删元素（pop_back）
//    void pop_back() {
//        if (empty()) {
//            return;  // 空数组，无需操作
//        }
//        --_size;  // 仅减少计数（无需修改内存，下次赋值会覆盖）
//    }
//
//    // 4.3 头插元素（push_front）
//    void push_front(const T& val) {
//        if (_size == _capacity) {
//            reserve(_capacity == 0 ? 1 : _capacity * 2);  // 扩容
//        }
//        // 所有元素向后移动1位（从最后一个元素开始）
//        for (size_t i = _size; i > 0; --i) {
//            _data[i] = _data[i - 1];
//        }
//        _data[0] = val;  // 插入到头部
//        ++_size;         // 有效元素数+1
//    }
//
//    // 4.4 头删元素（pop_front）
//    void pop_front() {
//        if (empty()) {
//            return;  // 空数组，无需操作
//        }
//        // 所有元素向前移动1位（覆盖头部元素）
//        for (size_t i = 0; i < _size - 1; ++i) {
//            _data[i] = _data[i + 1];
//        }
//        --_size;  // 有效元素数-1
//    }
//
//    // 4.5 指定位置插入元素（insert）
//    void insert(size_t pos, const T& val) {
//        if (pos > _size) {
//            throw out_of_range("Vector::insert: pos out of range");  // 插入位置非法
//        }
//        if (_size == _capacity) {
//            reserve(_capacity == 0 ? 1 : _capacity * 2);  // 扩容
//        }
//        // 从pos位置开始，元素向后移动1位
//        for (size_t i = _size; i > pos; --i) {
//            _data[i] = _data[i - 1];
//        }
//        _data[pos] = val;  // 插入元素
//        ++_size;           // 有效元素数+1
//    }
//
//    // 4.6 删除指定位置元素（erase）
//    void erase(size_t pos) {
//        if (pos >= _size) {
//            throw out_of_range("Vector::erase: pos out of range");  // 删除位置非法
//        }
//        // 从pos位置开始，元素向前移动1位（覆盖被删除元素）
//        for (size_t i = pos; i < _size - 1; ++i) {
//            _data[i] = _data[i + 1];
//        }
//        --_size;  // 有效元素数-1
//    }
//
//    // 4.7 清空所有元素（clear）
//    void clear() {
//        _size = 0;  // 仅重置计数，不释放内存（后续可复用）
//    }
//
//
//    // ====================== 5. 迭代器接口（支持范围for循环） ======================
//    // 5.1 普通迭代器（非const）
//    typedef T* iterator;
//    iterator begin() {
//        return _data;  // 指向第一个元素
//    }
//    iterator end() {
//        return _data + _size;  // 指向最后一个元素的下一位（哨兵位置）
//    }
//
//    // 5.2 const迭代器（只读）
//    typedef const T* const_iterator;
//    const_iterator begin() const {
//        return _data;
//    }
//    const_iterator end() const {
//        return _data + _size;
//    }
//
//
//private:
//    T* _data;       // 底层动态数组指针（存储元素）
//    size_t _capacity;// 数组总容量（能容纳的最大元素数）
//    size_t _size;    // 当前有效元素个数（用户感知的“长度”）
//};
//
//
//// ====================== 测试代码：验证所有接口功能 ======================
//int main() {
//    // 1. 测试构造与赋值
//    Vector<int> v1;  // 默认构造
//    Vector<int> v2(5, 10);  // 5个10
//    Vector<int> v3(v2);  // 拷贝构造
//    Vector<int> v4;
//    v4 = v3;  // 赋值运算符
//
//    cout << "v2（5个10）: ";
//    for (int x : v4) {  // 范围for（依赖迭代器begin/end）
//        cout << x << " ";
//    }
//    cout << endl;  // 输出：10 10 10 10 10
//
//
//    // 2. 测试容量管理
//    cout << "v4 size: " << v4.size() << ", capacity: " << v4.capacity() << endl;  // 5,5
//    v4.reserve(10);  // 预分配容量到10
//    cout << "v4 after reserve(10): capacity=" << v4.capacity() << endl;  // 10
//    v4.push_back(20);
//    v4.shrink_to_fit();  // 收缩容量到6
//    cout << "v4 after shrink_to_fit: capacity=" << v4.capacity() << endl;  // 6
//
//
//    // 3. 测试元素访问
//    cout << "v4[2]: " << v4[2] << endl;  // 10（下标访问）
//    cout << "v4.at(4): " << v4.at(4) << endl;  // 10（安全访问）
//    cout << "v4.front(): " << v4.front() << endl;  // 10（第一个元素）
//    cout << "v4.back(): " << v4.back() << endl;  // 20（最后一个元素）
//
//
//    // 4. 测试增删操作
//    v4.push_front(5);  // 头插5
//    v4.insert(3, 15);  // 位置3插入15
//    cout << "v4 after push_front & insert: ";
//    for (auto it = v4.begin(); it != v4.end(); ++it) {  // 迭代器遍历
//        cout << *it << " ";
//    }
//    cout << endl;  // 输出：5 10 10 15 10 10 20
//
//    v4.pop_front();  // 头删
//    v4.erase(2);     // 删除位置2
//    v4.pop_back();   // 尾删
//    cout << "v4 after pop_front & erase & pop_back: ";
//    for (int x : v4) {
//        cout << x << " ";
//    }
//    cout << endl;  // 输出：10 10 10 10
//
//
//    // 5. 测试清空
//    v4.clear();
//    cout << "v4 after clear: size=" << v4.size() << ", empty=" << v4.empty() << endl;  // 0, true
//
//
//    // 6. 测试异常（越界访问）
//    try {
//        v4.at(0);  // 空数组访问，抛出异常
//    }
//    catch (const out_of_range& e) {
//        cout << "Exception: " << e.what() << endl;  // 捕获异常并输出
//    }
//
//    return 0;
//}
