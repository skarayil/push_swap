# 🦋 push_swap - Verimli Stack Sıralama Algoritması

<div align="center">

![42 School](https://img.shields.io/badge/School-42-black?style=for-the-badge&logo=42)
![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Push Swap](https://img.shields.io/badge/Project-push__swap-blue?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)

**İki stack kullanarak sayıları minimum hareket sayısıyla sıralama algoritması**

*Bu proje, algoritma optimizasyonu, veri yapıları ve karmaşıklık analizi konularında derinlemesine deneyim kazandırırken, Butterfly (Kelebek) algoritması ile büyük veri setlerini verimli şekilde sıralamayı öğretir.*

[Kurulum](#-kurulum) • [Kullanım](#-kullanım) • [Özellikler](#-desteklenen-özellikler) • [Bonus](#-bonus-kısmı)

</div>

---

## 🎯 Projenin Amacı

<img align="right" alt="Sorting Algorithm Animation" width="300" src="https://media1.giphy.com/media/v1.Y2lkPTc5MGI3NjExY3JzdXc1a2MxejR5YnBxeWlmdXp3b3VraGh0eGk4enJ2dmhkMGFvaSZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/usXZmmgP9Z7kf39fnq/giphy.gif">

Bu proje, **iki stack (yığın) veri yapısı kullanarak sayıları minimum hareket sayısıyla sıralama** algoritması geliştirmeyi amaçlar. Proje, algoritma tasarımı ve optimizasyon konularında kapsamlı deneyim sağlar.

### 🎓 **Ana Öğrenme Hedefleri:**

#### 📚 **Veri Yapıları ve Stack İşlemleri**
- Doubly linked list implementasyonu ile stack yapısı oluşturma
- Stack operasyonları (push, pop, swap, rotate, reverse rotate)
- İki stack arasında verimli veri transferi yönetimi
- Memory-efficient data structure design ve pointer manipulation

#### 🦋 **Butterfly (Kelebek) Algoritması**
- Chunk-based sorting yaklaşımı ile büyük veri setlerini bölme
- Optimal chunk size hesaplaması ve performans optimizasyonu
- Range-based element distribution stratejisi
- İki fazlı sıralama: Distribution ve Extraction

#### 🧮 **Algoritma Optimizasyonu ve Complexity Analysis**
- Time complexity analizi (O(n), O(n log n))
- Space complexity optimization
- Move count minimization techniques
- Farklı veri boyutları için adaptive algorithm selection

#### 🎯 **Problem Çözme Stratejileri**
- Küçük sayı setleri için özel algoritmalar (2, 3, 4, 5 eleman)
- Büyük sayı setleri için Butterfly algoritması
- Index-based sorting optimization (O(1) comparison)
- Pattern recognition ve sorting patterns

#### 🔧 **Input Parsing ve Validasyon**
- Multiple input format handling (single string, multiple arguments)
- Duplicate detection ve error handling
- Integer overflow/underflow prevention
- Robust input validation ve edge case handling

#### 🧪 **Test ve Doğrulama Metodolojileri**
- Checker program ile sorting verification
- Performance benchmarking ve move count tracking
- Edge case testing ve stress testing
- Memory leak detection ve prevention

---

## ✨ Desteklenen Özellikler

<div align="center">

![Stack Operations](https://img.shields.io/badge/Stack-Operations-brightgreen?style=for-the-badge)
![Butterfly Algorithm](https://img.shields.io/badge/Butterfly-Algorithm-blue?style=for-the-badge)
![Optimized Sorting](https://img.shields.io/badge/Optimized-Sorting-orange?style=for-the-badge)

</div>

### 📋 **Stack Operasyonları**

| Operasyon | Kod | Açıklama | Complexity |
|-----------|-----|----------|------------|
| **swap a** | `sa` | Stack A'nın ilk iki elemanını değiştirir | O(1) |
| **swap b** | `sb` | Stack B'nin ilk iki elemanını değiştirir | O(1) |
| **swap both** | `ss` | Her iki stack'in ilk iki elemanını değiştirir | O(1) |
| **push a** | `pa` | Stack B'nin tepesini Stack A'ya iter | O(1) |
| **push b** | `pb` | Stack A'nın tepesini Stack B'ye iter | O(1) |
| **rotate a** | `ra` | Stack A'yı yukarı kaydırır (ilk → son) | O(1) |
| **rotate b** | `rb` | Stack B'yi yukarı kaydırır (ilk → son) | O(1) |
| **rotate both** | `rr` | Her iki stack'i yukarı kaydırır | O(1) |
| **reverse rotate a** | `rra` | Stack A'yı aşağı kaydırır (son → ilk) | O(1) |
| **reverse rotate b** | `rrb` | Stack B'yi aşağı kaydırır (son → ilk) | O(1) |
| **reverse rotate both** | `rrr` | Her iki stack'i aşağı kaydırır | O(1) |

### 🔄 **Çalışma Prensibi**

```
Input → Parse & Validate → Index Assignment → Algorithm Selection → Sorting
  ↓           ↓                   ↓                    ↓              ↓
Numbers    Duplicate          [0,1,2,3,4]         Butterfly      Operations
          Check OK                              or Caterpillar    (sa,pb,ra)
```

### 🦋 **Butterfly Algorithm Features**

| Özellik | Açıklama | Avantaj |
|---------|----------|---------|
| **Chunk-based Distribution** | Veriyi chunk'lara bölerek işleme | Balanced workload |
| **Adaptive Chunk Size** | Veri boyutuna göre optimal chunk | Performance optimization |
| **Two-phase Sorting** | Distribution + Extraction | Clear algorithm structure |
| **Index-based Comparison** | Sayı yerine index karşılaştırma | O(1) comparison time |

### 📊 **Performance Characteristics**

```
Algorithm Performance by Input Size:
│
├── 2-3 Elements: Pattern-based (0-2 moves)
├── 4-5 Elements: Hybrid approach (≤12 moves)
├── 100 Elements: Butterfly (~600 moves, target <700)
└── 500 Elements: Butterfly (~5000 moves, target <5500)
```

---

## 🎁 Bonus Kısmı

<div align="center">

![Checker](https://img.shields.io/badge/Checker-Program-gold?style=for-the-badge)
![Validation](https://img.shields.io/badge/Move-Validation-purple?style=for-the-badge)

</div>

Bonus kısmında, push_swap'in ürettiği hareketleri doğrulayan bir **checker** programı geliştirilir:

### ✅ **Checker Program Özellikleri**

| Özellik | Açıklama | Avantaj |
|---------|----------|---------|
| **Move Validation** | Hareketlerin doğruluğunu kontrol eder | Correctness verification |
| **Result Checking** | Stack'in sıralı olup olmadığını doğrular | Final state validation |
| **stdin Input** | get_next_line ile hareketleri okur | Flexible testing |
| **Error Detection** | Geçersiz hareketleri tespit eder | Robust verification |

### 📊 **Checker Çalışma Prensibi**

```
stdin Input → Parse Instructions → Execute Moves → Validate State → Output
     ↓               ↓                   ↓              ↓           ↓
"sa\npb\npa"    Validate Each      Apply to Stacks  Check Sort   OK/KO
                Instruction                          & Empty B    /Error
```

### 🔧 **Checker Kullanım Senaryoları**

#### ✅ **Başarılı Sıralama Doğrulaması**
```bash
# push_swap çıktısını checker'a pipe et
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG
# Output: OK

# 100 eleman test
ARG=$(seq 1 100 | shuf | tr '\n' ' ')
./push_swap $ARG | ./checker $ARG
# Output: OK
```

#### ❌ **Başarısız Sıralama Testi**
```bash
# Manuel hareketler (yanlış sıralama)
echo -e "sa\npb" | ./checker 4 67 3 87 23
# Output: KO

# Eksik hareketler
echo -e "pb\npa" | ./checker 3 2 1
# Output: KO
```

#### ⚠️ **Hata Durumu Testi**
```bash
# Geçersiz hareket
echo -e "invalid_move" | ./checker 4 67 3 87 23
# Output: Error

# Geçersiz input
echo -e "sa\npb" | ./checker 1 2 2 3
# Output: Error (duplicate input)
```

### 🎯 **Bonus Implementation Details**

```c
// Checker main loop
while ((line = get_next_line(0)) != NULL) {
    if (!ft_apply_exec(data, line)) {
        free(line);
        ft_error_exit(data);  // Invalid instruction
    }
    free(line);
}

// Final validation
if (ft_is_sorted(data->stack_a) && !data->stack_b)
    write(1, "OK\n", 3);
else
    write(1, "KO\n", 3);
```

---

## 📁 Dosya Yapısı

```
push_swap/
│
├── 📄 Makefile                      # Build automation ve derleme kuralları
│
├── 📂 sources/                      # Ana program kaynak dosyaları
│   ├── 🎯 main.c                    # Program entry point ve initialization
│   ├── 🦋 butterfly.c               # Butterfly algoritması (büyük setler)
│   ├── 🐛 caterpillar.c             # Küçük set algoritmaları (2-5 eleman)
│   ├── 📝 parsing.c                 # Input parsing ve validation
│   ├── 📊 array.c                   # Array sorting ve index assignment
│   ├── 🔧 stack.c                   # Stack veri yapısı operations
│   ├── 🔄 push.c                    # Push operations (pa, pb)
│   ├── ↻ rotate.c                   # Rotate operations (ra, rb, rr)
│   ├── ↺ rev_rotate.c               # Reverse rotate (rra, rrb, rrr)
│   ├── 🔀 swap.c                    # Swap operations (sa, sb, ss)
│   └── 🛠️ utils.c                   # Utility functions
│
├── 📂 bonus/                        # Bonus checker programı
│   ├── 📂 sources/
│   │   ├── ✅ checker.c             # Checker main program
│   │   ├── ⚙️ executer.c            # Instruction execution
│   │   ├── 🔧 *_bonus.c             # Stack operations (bonus version)
│   │   ├── 📊 array_bonus.c         # Array operations
│   │   ├── 📝 parsing_bonus.c       # Input parsing
│   │   ├── 🔧 stack_bonus.c         # Stack operations
│   │   └── 🛠️ utils_bonus.c         # Utility functions
│   ├── 📂 library/
│   │   └── 📖 get_next_line/        # stdin okuma için GNL
│   │       ├── get_next_line.c
│   │       ├── get_next_line.h
│   │       └── get_next_line_utils.c
│   └── 📂 include/
│       └── 📋 push_swap_bonus.h     # Bonus header definitions
│
├── 📂 include/                      # Header dosyaları
│   └── 📋 push_swap.h               # Ana header (structs, prototypes)
│
├── 📂 library/                      # Kullanılan kütüphaneler
│   ├── 📚 libft/                    # 42 libft kütüphanesi
│   │   ├── Makefile
│   │   ├── libft.h
│   │   └── *.c                      # String, memory, list functions
│   └── 🖨️ printf/                   # ft_printf kütüphanesi
│       ├── Makefile
│       ├── ft_printf.h
│       └── ft_printf*.c             # Printf implementation
│
└── 📖 README.md                     # Proje dokümantasyonu
```

### 📊 **Dosya Açıklamaları**

| Dosya | İçerik | Sorumluluk |
|-------|--------|------------|
| `butterfly.c` | Butterfly algoritması | Chunk-based sorting for 6+ elements |
| `caterpillar.c` | Küçük set algoritmaları | Optimized sorting for 2-5 elements |
| `parsing.c` | Input işleme | Argument parsing, validation, error handling |
| `array.c` | Array işlemleri | Insertion sort, indexing, duplicate check |
| `stack.c` | Stack operasyonları | Stack creation, cleanup, node management |
| `push.c` | Push operasyonları | pa, pb implementations |
| `rotate.c` | Rotate operasyonları | ra, rb, rr implementations |
| `rev_rotate.c` | Reverse rotate | rra, rrb, rrr implementations |
| `swap.c` | Swap operasyonları | sa, sb, ss implementations |
| `checker.c` (bonus) | Doğrulama programı | Move validation, result checking |
| `executer.c` (bonus) | Hareket yürütücü | Instruction parsing and execution |

---

## 🚀 Kurulum

### 📋 **Ön Gereksinimler**

![GCC](https://img.shields.io/badge/GCC-Required-red?style=flat-square&logo=gnu&logoColor=white)
![Make](https://img.shields.io/badge/Make-Required-blue?style=flat-square&logo=gnu&logoColor=white)
![Unix](https://img.shields.io/badge/Unix-Compatible-green?style=flat-square&logo=linux&logoColor=white)

- **C Compiler**: `gcc` veya `clang`
- **Make**: Build automation tool
- **Unix-like System**: Linux, macOS, WSL

### 📥 **Repository Klonlama**

```bash
# Projeyi yerel sisteminize klonlayın
git clone https://github.com/skarayil/push_swap.git
cd push_swap
```

### 🔨 **Derleme İşlemi**

```bash
# Ana programı derle
make

# Bonus (checker) programını derle
make bonus

# Temizlik işlemleri
make clean          # Object dosyalarını sil
make fclean         # Tüm oluşturulan dosyaları sil
make re             # Yeniden derle (fclean + make)
```

### 📦 **Çıktı Dosyaları**

```bash
push_swap           # Ana sıralama programı
checker             # Bonus doğrulama programı (make bonus ile)
```

---

## 💻 Kullanım

### 🎯 **Temel Kullanım**

#### 🟢 **1. Sayıları Sıralama**

```bash
# Birden fazla argüman ile
./push_swap 4 67 3 87 23

# Tek string argüman ile (boşlukla ayrılmış)
./push_swap "4 67 3 87 23"

# Çıktı: Sıralama hareketleri
pb
pb
ra
sa
pa
pa
ra
```

#### 🟡 **2. Hareket Sayısını Görme**

```bash
# Hareket sayısını say
./push_swap 4 67 3 87 23 | wc -l

# Çıktı: Total move count (örn: 6)
```

#### 🔴 **3. Farklı Input Formatları**

```bash
# Pozitif sayılar
./push_swap 5 3 1 4 2

# Negatif sayılar
./push_swap -5 -3 -1 -4 -2

# Karışık
./push_swap -2 5 0 -7 3

# Açık işaretler
./push_swap +5 -3 +1 0
```

### 📝 **Kullanım Örnekleri**

#### 🟢 **Küçük Sayı Seti (2-5 eleman)**

```bash
# 2 eleman
./push_swap 2 1
# Çıktı: sa (veya boş eğer zaten sıralıysa)

# 3 eleman (maksimum 2 hareket)
./push_swap 3 2 1
# Çıktı:
sa
rra

# 5 eleman (maksimum 12 hareket)
./push_swap 5 4 3 2 1
./push_swap 5 4 3 2 1 | wc -l
# Çıktı: ≤12
```

#### 🟡 **Orta Boyut (100 eleman)**

```bash
# 100 rastgele sayı üret ve sırala
ARG=$(seq 1 100 | shuf | tr '\n' ' ')
./push_swap $ARG | wc -l

# Beklenen: <700 hareket
# Örnek çıktı: 623

# Hareket sayısını değişkene ata
MOVES=$(./push_swap $ARG | wc -l)
echo "Move count: $MOVES"
```

#### 🔴 **Büyük Boyut (500 eleman)**

```bash
# 500 rastgele sayı üret ve sırala
ARG=$(seq 1 500 | shuf | tr '\n' ' ')
MOVES=$(./push_swap $ARG | wc -l)
echo "Move count for 500 elements: $MOVES"

# Beklenen: <5500 hareket
# Örnek çıktı: Move count for 500 elements: 5234
```

#### 🟣 **Özel Durumlar**

```bash
# Zaten sıralı (boş output)
./push_swap 1 2 3 4 5
# Çıktı: (boş - hareket gerekmez)

# Ters sıralı
./push_swap 5 4 3 2 1
./push_swap 5 4 3 2 1 | wc -l

# Tek eleman
./push_swap 42
# Çıktı: (boş - hareket gerekmez)
```

### 🎁 **Bonus: Checker Kullanımı**

#### ✅ **Doğrulama Testleri**

```bash
# push_swap çıktısını checker'a gönder
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG
# Çıktı: OK (başarılı sıralama)

# 100 eleman doğrulama
ARG=$(seq 1 100 | shuf | tr '\n' ' ')
./push_swap $ARG | ./checker $ARG
# Çıktı: OK

# 500 eleman doğrulama
ARG=$(seq 1 500 | shuf | tr '\n' ' ')
./push_swap $ARG | ./checker $ARG
# Çıktı: OK
```

#### ❌ **Manuel Hareket Testi**

```bash
# Doğru sıralama
echo -e "sa" | ./checker 2 1 3
# Çıktı: OK

# Yanlış sıralama
echo -e "sa\npb" | ./checker 4 67 3 87 23
# Çıktı: KO (eksik hareketler)

# Geçersiz hareket
echo -e "invalid" | ./checker 4 67 3 87 23
# Çıktı: Error
```

#### 🔧 **Dosyadan Hareket Okuma**

```bash
# Hareketleri dosyaya kaydet
./push_swap 5 4 3 2 1 > moves.txt

# Dosyadan oku ve doğrula
./checker 5 4 3 2 1 < moves.txt
# Çıktı: OK
```

---

## 📚 Notlar

### ⚠️ **Önemli Dikkat Edilmesi Gerekenler**

#### 🛡️ **Bellek Yönetimi**
- **Doubly Linked List**: Her node'un `prev` ve `next` pointer'larının doğru şekilde yönetilmesi kritiktir
- **Memory Leaks**: Stack clear işlemlerinde tüm node'ların serbest bırakılması gerekir
- **malloc() Kontrolü**: Her malloc çağrısının return value'sunun kontrol edilmesi zorunludur
- **Error Handling**: Parse hatalarında belleğin temizlenmesi ve program exit işlemi
- **Valgrind Testing**: Memory leak testi için `valgrind --leak-check=full` kullanılmalıdır

#### 🔧 **Algoritma Seçimi ve Optimizasyon**
- **Input Size Check**: Algoritma seçimi veri boyutuna göre yapılmalıdır
  - 2 eleman → Simple swap
  - 3 eleman → Pattern-based sort
  - 4-5 eleman → Hybrid approach
  - 6+ eleman → Butterfly algorithm
- **Already Sorted**: Program başında sıralı kontrolü yaparak gereksiz işlemlerden kaçınma
- **Index Assignment**: O(n²) insertion sort kullanılarak index'lerin atanması
- **Chunk Calculation**: Veri boyutuna göre optimal chunk size hesaplaması

#### 📊 **Performance Kriterleri**
- **Move Count**: Her test için maksimum hareket sayısı hedefleri:
  - 3 eleman: ≤3 hareket (ideal: ≤2)
  - 5 eleman: ≤12 hareket
  - 100 eleman: <700 hareket (ideal: ~600)
  - 500 eleman: <5500 hareket (ideal: ~5000)
- **Rotation Direction**: Her zaman en kısa yolu seçme (`size/2` kontrolü)
- **Operation Optimization**: Gereksiz hareketlerden kaçınma (örn: zaten sıralıysa işlem yapma)

#### 🔍 **Input Validation**
- **Duplicate Detection**: Aynı sayının birden fazla kez gelmemesi kontrolü
- **Integer Overflow/Underflow**: `INT_MIN` ve `INT_MAX` sınırlarının kontrolü
- **Non-numeric Input**: Sadece sayı ve +/- işaretlerinin kabul edilmesi
- **Empty Input**: Boş argüman durumunda sessiz çıkış yapılması
- **Leading Zeros**: `001`, `002` gibi girdilerin doğru parse edilmesi

#### 🎯 **Butterfly Algorithm İncelikleri**
- **Chunk Size**: Veri boyutuna göre adaptive chunk size kullanımı
- **Distribution Phase**: Element index'ine göre doğru stratejinin uygulanması
  - `index ≤ counter`: Push to B + Rotate B
  - `index ≤ counter + chunk`: Just Push to B
  - `index > counter + chunk`: Rotate A
- **Extraction Phase**: Stack B'den maksimum elemanı bulup optimal yönde rotate etme
- **Counter Management**: Distribution phase'de counter'ın doğru artırılması

#### 🧪 **Testing Best Practices**
- **Edge Cases**: Minimum/maximum integer değerleri, tek eleman, iki eleman testleri
- **Random Testing**: Farklı permütasyonlarla test edilmesi
- **Performance Testing**: Farklı veri boyutlarında (10, 50, 100, 500) test yapılması
- **Valgrind**: Her test sonrası memory leak kontrolü yapılması
- **Checker Validation**: Her sıralama sonucunun checker ile doğrulanması

#### 💡 **Code Quality Tips**
- **Modular Design**: Her operasyon için ayrı dosya ve fonksiyon
- **Function Size**: Fonksiyonların 25 satırı geçmemesine dikkat
- **Norminette**: 42 Norm kurallarına tam uyum
- **Error Messages**: Sadece "Error\n" mesajı stderr'e yazılmalı
- **Return Values**: Ana program exit(0) veya exit(1) ile çıkmalı

#### 🔬 **Debug ve Geliştirme**
- **Visual Debugging**: Stack durumunu yazdırma fonksiyonları (geçici debug için)
- **Move Counter**: Hareket sayısını takip etme mekanizması
- **Algorithm Trace**: Butterfly phase'lerini loglama (development sırasında)
- **Visualizer Tools**: push_swap_visualizer gibi araçların kullanımı
- **Test Scripts**: Otomatik test scriptleri hazırlama

---

## 🏆 Proje Başarıları

<div align="center">

![Score](https://img.shields.io/badge/Score-125%2F100-gold?style=for-the-badge)
![Tests](https://img.shields.io/badge/Tests-All%20Passed-success?style=for-the-badge)
![Norminette](https://img.shields.io/badge/Norminette-OK-brightgreen?style=for-the-badge)
![Bonus](https://img.shields.io/badge/Bonus-Completed-orange?style=for-the-badge)

### 📊 **Proje İstatistikleri**

| Metrik | Değer |
|--------|-------|
| **Source Files** | 11 (Main) + 8 (Bonus) |
| **Total Functions** | 40+ |
| **Stack Operations** | 11 different operations |
| **Algorithms Implemented** | 4 (2-elem, 3-elem, 4-5-elem, Butterfly) |
| **Lines of Code** | ~1500+ |
| **Test Cases Passed** | 100+ |
| **Memory Leak Tests** | ✅ Valgrind Clean |
| **Bonus Completion** | ✅ Full Implementation |

### 🎖️ **Performance Achievements**

| Test Category | Target | Achieved | Status |
|---------------|--------|----------|---------|
| **3 elements** | ≤3 moves | ≤2 moves | ⭐⭐⭐⭐⭐ |
| **5 elements** | ≤12 moves | ~8-12 moves | ⭐⭐⭐⭐⭐ |
| **100 elements** | <700 moves | ~550-650 moves | ⭐⭐⭐⭐⭐ |
| **500 elements** | <5500 moves | ~4800-5300 moves | ⭐⭐⭐⭐⭐ |

</div>

### 🦋 **Butterfly Algorithm Performance**

```
Average Performance Metrics:
│
├── 100 elements
│   ├── Average: ~600 moves
│   ├── Best case: ~550 moves
│   └── Worst case: ~650 moves
│
└── 500 elements
    ├── Average: ~5000 moves
    ├── Best case: ~4800 moves
    └── Worst case: ~5300 moves
```

<div align="center">
  
### 🎯 **Core Skills Gained**

![Algorithm Design](https://img.shields.io/badge/Algorithm-Design-blue?style=flat-square)
![Data Structures](https://img.shields.io/badge/Data-Structures-green?style=flat-square)
![Optimization](https://img.shields.io/badge/Optimization-orange?style=flat-square)
![Problem Solving](https://img.shields.io/badge/Problem-Solving-purple?style=flat-square)
![Memory Management](https://img.shields.io/badge/Memory-Management-red?style=flat-square)

</div>

### 🌟 **Key Accomplishments**

#### 🏅 **Technical Achievements**
- **Butterfly Algorithm**: Successfully implemented chunk-based sorting with optimal performance
- **Memory Efficiency**: Zero memory leaks across all test scenarios
- **Code Quality**: 100% Norminette compliance with clean, modular design
- **Performance**: Consistently meeting or exceeding all performance targets
- **Bonus Integration**: Seamless checker implementation with shared codebase

#### 📈 **Learning Outcomes**
- **Algorithm Mastery**: Deep understanding of sorting algorithms and optimization
- **Data Structure Expertise**: Proficient in doubly linked lists and stack operations
- **Complexity Analysis**: Ability to analyze and optimize time/space complexity
- **Problem Decomposition**: Breaking complex problems into manageable components
- **Testing Methodology**: Comprehensive testing strategies and validation techniques

---

<div align="center">

**🦋 "The butterfly effect in sorting: small, strategic moves create perfectly ordered results."**

*Bu proje, algoritma tasarımının bir sanat olduğunu ve doğru yaklaşımla karmaşık problemlerin elegant çözümler bulabileceğini gösterir. Butterfly algoritması, doğadaki kelebek kanatlarının simetrik yapısından ilham alarak, veriyi dengeli bir şekilde dağıtma ve toplama prensibini kullanır.*

---

### 👨‍💻 Created by Sude Naz Karayıldırım

[![42 Profile](https://img.shields.io/badge/42%20Profile-skarayil-black?style=flat-square&logo=42&logoColor=white)](https://profile.intra.42.fr/users/skarayil)
[![GitHub](https://img.shields.io/badge/GitHub-skarayil-181717?style=flat-square&logo=github&logoColor=white)](https://github.com/skarayil)

**⭐ Eğer bu proje işinize yaradıysa, repo'ya star vermeyi unutmayın!**

</div>
