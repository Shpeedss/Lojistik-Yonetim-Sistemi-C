# Lojistik Yönetim Sistemi (C Programlama)

Bu proje, Algoritmalar ve Veri Yapıları dersi kapsamında geliştirilmiş bir lojistik ağ ve paket yönetim simülasyonudur. Sistem, donanıma yakın seviyede bellek yönetimi (dinamik bellek tahsisi) prensiplerine uygun olarak C dilinde yazılmıştır.

## 📌 Proje Özellikleri ve Algoritmalar
Öğrenci numarasına bağlı yönergeler doğrultusunda şu yapılar kullanılmıştır:
* **Graf (Graph):** Şehirler arası rotaların tutulması (Komşuluk Listesi ile bellek optimizasyonu).
* **Hash Tablosu:** Paket kayıtlarının O(1) zaman karmaşıklığında sorgulanması.
* **Hash Fonksiyonu:** Tip A (Modulo Aritmetiği).
* **Çakışma Yönetimi:** Açık Adresleme (Linear Probing / Doğrusal Yoklama).
* **Graf Gezinme:** DFS (Derinlik Öncelikli Arama).

## 📂 Dosya Mimarisi
Proje, mantıksal katmanlarına göre çoklu dosya (multi-file) yapısında tasarlanmıştır:
* `main.c`: Ana test ve sistem döngüsü.
* `graph.h / graph.c`: Şehir bağlantıları ve DFS algoritması işlemleri.
* `hash.h / hash.c`: Paket indeksleme ve çakışma (collision) çözümleri.

## 🚀 Kurulum ve Çalıştırma
Bu projeyi derlemek için GCC derleyicisi gereklidir. Terminal veya komut satırında:
```bash
gcc main.c hash.c graph.c -o lojistik_sistemi
./lojistik_sistemi
