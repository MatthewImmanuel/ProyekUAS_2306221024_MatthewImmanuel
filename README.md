# Vehicle Performance Simulation  
## Simulasi Analisis Performa Kendaraan dengan Metode Gauss-Legendre Quadrature Orde 3  

---

### Informasi Proyek

| Field            | Detail                       |
|------------------|------------------------------|
| Proyek           | UAS Komputasi Numerik        |
| Nama             | Matthew Immanuel Sitorus     |
| NPM              | 2306221024                   |
| Tahun            | 2024                         |
| Mata Kuliah      | Komputasi Numerik            |

---

### Deskripsi Program

Program ini merupakan implementasi simulasi analisis performa kendaraan yang menggunakan metode integrasi numerik **Gauss-Legendre Quadrature orde 3** untuk menghitung parameter kinematika kendaraan berdasarkan fungsi percepatan yang berubah terhadap waktu.

#### Fungsi Percepatan
a(t) = 3 sin(t) + 0.5 t²


Simulasi dilakukan selama 10 detik dengan interval diskretisasi 0.5 detik. Output program mencakup:
- Percepatan instant  
- Kecepatan kumulatif  
- Jarak tempuh total  

---

### Tujuan dan Manfaat

**Tujuan Utama:**
- Implementasi metode integrasi numerik untuk masalah kinematika
- Analisis performa kendaraan dengan fungsi percepatan nonlinier
- Validasi akurasi metode Gauss-Legendre Quadrature

**Manfaat Praktis:**
- *Engineering:* Analisis dinamika kendaraan
- *Research:* Studi komputasi numerik
- *Education:* Pembelajaran integrasi numerik

---

### Metode Numerik

#### Gauss-Legendre Quadrature Orde 3

**Formula Integrasi:**
∫[a,b] f(t) dt ≈ (b-a)/2 × Σ[i=1 to 3] wᵢ · f(tᵢ)


**Parameter Kuadratur:**

| Titik Evaluasi (xᵢ) | Bobot (wᵢ)     |
|---------------------|----------------|
| -√(3/5) ≈ -0.7746    | 5/9 ≈ 0.5556   |
| 0.0000              | 8/9 ≈ 0.8889   |
| +√(3/5) ≈ +0.7746    | 5/9 ≈ 0.5556   |

**Transformasi Interval:**
tᵢ = (b-a)/2 · xᵢ + (b+a)/2

---

### Algoritma Simulasi

**Langkah Simulasi:**
1. **Inisialisasi Parameter:**
   - `t_start = 0.0 s`
   - `t_end = 10.0 s`
   - `Δt = 0.5 s`
   - `v₀ = 0 m/s`, `s₀ = 0 m`

2. **Loop Simulasi (per Δt):**
   - Hitung percepatan: `a(t) = 3 sin(t) + 0.5 t²`
   - Integrasi kecepatan: `Δv = ∫[t to t+Δt] a(τ) dτ`
   - Update kecepatan: `v(t+Δt) = v(t) + Δv`
   - Hitung jarak: `Δs = v_avg × Δt`
   - Update posisi: `s(t+Δt) = s(t) + Δs`

---

### Output

Program menampilkan tabel waktu, percepatan, kecepatan, dan jarak ke layar serta menyimpannya dalam file `hasil_simulasi.csv`.  
Juga ditampilkan:
- Total jarak tempuh  
- Kecepatan akhir kendaraan  

---



