#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY


#include "utils.hpp"


namespace ts {
  template<typename ArrayType>
  class DynamicArray {
  public:
    enum class State {
      OK,
      UNABLE_TO_ALLOC,
      INVALID_ID
    };
  private:
    static const size_t DEFAULT_CAPACITY = 8;

    size_t size = 0;
    size_t capacity = DEFAULT_CAPACITY;
    ArrayType* buffer;

    State state = State::OK;

    size_t CountCapacity(size_t size);

    ArrayType* AllocateBuffer(size_t new_capacity);
  public:
    DynamicArray();
    DynamicArray(size_t size);
    DynamicArray(size_t size, const ArrayType& value);
    DynamicArray(const DynamicArray& other);
    ~DynamicArray();

    size_t Size() const;
    State GetState() const;

    const ArrayType& operator[] (size_t id) const;
    ArrayType& operator[] (size_t id);
    DynamicArray<ArrayType>& operator= (const DynamicArray<ArrayType>& other);

    void Resize(size_t new_size);
    void PushBack(const ArrayType& value);
  };


  template<typename ArrayType>
  DynamicArray<ArrayType>::DynamicArray() {
    buffer = AllocateBuffer(capacity);
    if (state != State::OK)
      return;
    state = State::OK;
  }


  template<typename ArrayType>
  DynamicArray<ArrayType>::DynamicArray(size_t size): size(size) {
    capacity = CountCapacity(size);
    buffer = AllocateBuffer(capacity);
    if (state != State::OK)
      return;
  }


  template<typename ArrayType>
  DynamicArray<ArrayType>::DynamicArray(size_t size, const ArrayType& value):
                           size(size) {
    capacity = CountCapacity(size);
    buffer = AllocateBuffer(capacity);
    if (state != State::OK)
      return;
    for (size_t i = 0; i < size; ++i)
      buffer[i] = value;
  }


  template<typename ArrayType>
  DynamicArray<ArrayType>::DynamicArray(const DynamicArray<ArrayType>& other):
                           size(other.size), capacity(other.capacity) {
    buffer = AllocateBuffer(capacity);
    if (state != State::OK)
      return;
    for (size_t i = 0; i < size; ++i)
      buffer[i] = other[i];
  }


  template<typename ArrayType>
  DynamicArray<ArrayType>::~DynamicArray() {
    if (capacity != 0)
      delete[] buffer;
  }


  template<typename ArrayType>
  ArrayType* DynamicArray<ArrayType>::AllocateBuffer(size_t new_capacity) {
    if (new_capacity == 0)
      return nullptr;
    ArrayType* new_buffer = new ArrayType[new_capacity];
    if (new_buffer == nullptr)
      state = State::UNABLE_TO_ALLOC;
    return new_buffer;
  }


  template<typename ArrayType>
  size_t DynamicArray<ArrayType>::CountCapacity(size_t size) {
    size_t new_capacity = capacity;
    if (size == 0)
      return DEFAULT_CAPACITY;
    while (size > new_capacity)
      new_capacity = new_capacity<<1;
    while ((size<<1) < new_capacity)
      new_capacity = new_capacity>>1;
    return new_capacity;
  }


  template<typename ArrayType>
  size_t DynamicArray<ArrayType>::Size() const {
    return size;
  }


  template<typename ArrayType>
  typename DynamicArray<ArrayType>::State DynamicArray<ArrayType>::GetState() const {
    return state;
  }


  template<typename ArrayType>
  const ArrayType& DynamicArray<ArrayType>::operator[] (size_t id) const {
    return buffer[id];
  }


  template<typename ArrayType>
  ArrayType& DynamicArray<ArrayType>::operator[] (size_t id) {
    if (id >= size)
      state = State::INVALID_ID;
    return buffer[id];
  }


  template<typename ArrayType>
  DynamicArray<ArrayType>& DynamicArray<ArrayType>::operator= (const DynamicArray<ArrayType>& other) {
    if (this != &other) {
      Resize(other.size);
      if (state == State::OK) {
        for (size_t i = 0; i < size; ++i)
          buffer[i] = other[i];
      }
    }
    return *this;
  }


  template<typename ArrayType>
  void DynamicArray<ArrayType>::Resize(size_t new_size) {
    size_t new_capacity = CountCapacity(new_size);
    if (new_capacity == capacity) {
      size = new_size;
      return;
    }
    ArrayType* new_buffer = AllocateBuffer(new_capacity);
    if (state != State::OK)
      return;
    size_t min_size = min(new_size, size);
    for (size_t i = 0; i < min_size; ++i)
      new_buffer[i] = buffer[i];
    delete[] buffer;
    buffer = new_buffer;
    capacity = new_capacity;
    size = new_size;
  }


  template<typename ArrayType>
  void DynamicArray<ArrayType>::PushBack(const ArrayType& value) {
    Resize(size + 1);
    if (state != State::OK)
      return;
    buffer[size - 1] = value;
  }
}


#endif /* dynamic_array.hpp */
