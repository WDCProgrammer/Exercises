#ifndef KEY_VALUE_PAIR_H
#define KEY_VALUE_PAIR_H

#include <string>
#include <concepts>

template <std::integral K, std::floating_point V>
class KeyValuePair
{
    public:
        KeyValuePair()                              = default;
        KeyValuePair(K _key, V _value)              noexcept;
        KeyValuePair(const KeyValuePair& kvp)       = default;
        KeyValuePair(KeyValuePair&& kvp)            = default ;
        ~KeyValuePair()                             = default;

        KeyValuePair&               operator=(const KeyValuePair& kvp) = default;
        KeyValuePair&               operator=(KeyValuePair&& kvp) = default;

        
        const K&                    GetKey()         const noexcept;
        const V&                    GetValue()       const noexcept;
        void                        SetValue(const V& _val)       noexcept;

    private:
        K               key;
        V               value;


};

    template <std::integral K, std::floating_point V>
    KeyValuePair<K,V>::KeyValuePair(K _key, V _value)noexcept : key(_key), value(_value){}

    template <std::integral K, std::floating_point V>
    const K& KeyValuePair<K,V>::GetKey()const noexcept
    {
        return key;
    }

    template <std::integral K, std::floating_point V>
    const V& KeyValuePair<K,V>::GetValue()const noexcept
    {
        return value;
    }

    template <std::integral K, std::floating_point V>
    void KeyValuePair<K,V>::SetValue(const V& _value) noexcept
    {
        value = _value;
    }

#endif