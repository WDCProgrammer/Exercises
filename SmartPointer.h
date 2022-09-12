#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

template <typename T>
class SmartPointer
{
public:
    SmartPointer(T *pt);
    ~SmartPointer();

    void                        Reset();
    T*                          Release();

    T&                          operator*();
    const T&                    operator*() const;
    T*                          operator->() const;

private:
    T*                          m_data{};
};

template <typename T>
SmartPointer<T>::SmartPointer(T *pt) : m_data(pt) 
{
    if(pt == nullptr)
    {
        //throw exception
    }
}

template <typename T>
void SmartPointer<T>::Reset()
{
    if (m_data)
        delete m_data;
    m_data = nullptr;
}

template <typename T>
T* SmartPointer<T>::operator->() const
{
    return m_data;
}

template <typename T>
T* SmartPointer<T>::Release()
{

    if (m_data)
    {
        auto temp       = m_data;
        m_data          = nullptr;
        return temp;
    }
    else
        return nullptr;
}

template <typename T>
T &SmartPointer<T>::operator*() 
{
    return *m_data;
}

template <typename T>
const T& SmartPointer<T>::operator*()const
{
    return *m_data;
}

template <typename T>
SmartPointer<T>::~SmartPointer()
{
    if (m_data)
    {
        std::cout << "Deleting Pointer.\n";

            delete m_data;
    }
}
#endif