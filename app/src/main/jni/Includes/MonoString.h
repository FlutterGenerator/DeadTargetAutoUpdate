#pragma once

using namespace std;
std::string 
utf16le_to_utf8(const std::u16string &u16str) {    
if (u16str.empty()) {
	return std::string();
}

const char16_t *p = u16str.data();   
std::u16string::size_type len = u16str.length();  
if (p[0] == 0xFEFF) {      
    p += 1;      
	len -= 1;   
} 

std::string u8str;   
u8str.reserve(len * 3);    
char16_t u16char;  
for (std::u16string::size_type i = 0; i < len; ++i) {       
     u16char = p[i];        
	 if (u16char < 0x0080) {          
	     u8str.push_back((char) (u16char & 0x00FF));          
		 continue;       
	 }      
	 if (u16char >= 0x0080 && u16char <= 0x07FF) {          
	     u8str.push_back((char) (((u16char >> 6) & 0x1F) | 0xC0));        
		 u8str.push_back((char) ((u16char & 0x3F) | 0x80));          
		 continue;       
	}      
	if (u16char >= 0xD800 && u16char <= 0xDBFF) {           
	    uint32_t highSur = u16char;          
		uint32_t lowSur = p[++i];          
		uint32_t codePoint = highSur - 0xD800;    
        codePoint <<= 10;        
		codePoint |= lowSur - 0xDC00;      
		codePoint += 0x10000;           
		u8str.push_back((char) ((codePoint >> 18) | 0xF0));     
		u8str.push_back((char) (((codePoint >> 12) & 0x3F) | 0x80));         
		u8str.push_back((char) (((codePoint >> 06) & 0x3F) | 0x80));            
		u8str.push_back((char) ((codePoint & 0x3F) | 0x80));        
	    continue;       
	} { 
	u8str.push_back((char) (((u16char >> 12) & 0x0F) | 0xE0));          
	u8str.push_back((char) (((u16char >> 6) & 0x3F) | 0x80));      
	u8str.push_back((char) ((u16char & 0x3F) | 0x80));         
	continue;      
	}    }   
	return u8str;
	} typedef struct _monoString {   
	void *klass;   
	void *monitor;    
	int length;    
	const char *toChars() {       
	u16string ss((char16_t *) getChars(), 0, getLength());     
	string str = utf16le_to_utf8(ss);  
	return str.c_str();   
	}    
	char chars[0];   
	char *getChars() {    
    return chars;    
	}  
	int getLength() {       
	return length;  
	}    
	std::string get_string() {             
	return std::string(toChars());  
	}} 
	monoString;
	
	template<typename T>
struct monoArray {
    void *klass;
    void *monitor;
    void *bounds;
    int capacity;
    T m_Items[0];

    int getCapacity() {
        return capacity;
    }

    T *getPointer() {
        return m_Items;
    }
    
    template<typename V = T>
    std::vector<V> toCPPlist() {
        std::vector<V> ret;
        for (int i = 0; i < capacity; i++)
            ret.push_back(m_Items[i]);
        return std::move(ret);
    }

    void copyFrom(std::vector<T> vec) {
        copyFrom(vec.data(), vec.size());
    }
    
    void copyFrom(T *arr, int size) {
        if (size > capacity)
            Resize(size);
        memcpy(arr, m_Items, capacity * sizeof(T));
    }

    void copyTo(T *arr) {
        memcpy(arr, m_Items, sizeof(T) * capacity);
    }
    
    T operator[] (int index) {
        return m_Items[index];
    }

    void Resize(int newSize) {
        if (newSize <= capacity) return;
        T* newArr = new T[newSize];
        memcpy(newArr, m_Items, capacity * sizeof(T));
        capacity = newSize;
    }
	
	monoArray<T>* MonoCreate(int size) {
		monoArray<T> *monoArr = (monoArray<T> *)malloc(sizeof(monoArray) + sizeof(T) * size);
        monoArr->capacity = size;
        return monoArr;
	}

    template<typename t>
    static monoArray<t> *Create(int size) {
        monoArray<t> *monoArr = (monoArray<t> *)malloc(sizeof(monoArray) + sizeof(t) * size);
        monoArr->capacity = size;
        return monoArr;
    }
    
    template<typename t>
    static monoArray<t> *Create(std::vector<t> vec) {
        return Create<t>(vec.data(), vec.size());
    }
    
    template<typename t>
    static monoArray<t> *Create(T *arr, int size) {
        monoArray<t> *monoArr = Create<t>(size);
        for (int i = 0; i < size; i++)
            monoArr->m_Items[i] = arr[i];
        return monoArr;
    }

};


