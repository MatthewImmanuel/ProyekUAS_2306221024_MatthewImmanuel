Vehicle Performance Simulation
Simulasi Analisis Performa Kendaraan dengan Metode Gauss-Legendre Quadrature Orde 3

Informasi Proyek
FieldDetailProyekUAS Komputasi NumerikNamaMatthew Immanuel SitorusNPM2306221024Tahun2024Mata KuliahKomputasi Numerik

Deskripsi Program
Program ini merupakan implementasi simulasi analisis performa kendaraan yang menggunakan metode integrasi numerik Gauss-Legendre Quadrature orde 3 untuk menghitung parameter kinematika kendaraan berdasarkan fungsi percepatan yang berubah terhadap waktu.
Fungsi Percepatan
a(t) = 3 sin(t) + 0.5 t²
Program melakukan simulasi selama 10 detik dengan interval diskretisasi 0.5 detik, menghasilkan data komprehensif tentang:

Percepatan instantan
Kecepatan kumulatif
Jarak tempuh total


Tujuan dan Manfaat
Tujuan Utama:

Implementasi metode integrasi numerik untuk masalah kinematika
Analisis performa kendaraan dengan fungsi percepatan nonlinier
Validasi akurasi metode Gauss-Legendre Quadrature

Manfaat Praktis:

Engineering: Analisis dinamika kendaraan
Research: Studi komputasi numerik
Education: Pembelajaran integrasi numerik


Metode Numerik
Gauss-Legendre Quadrature Orde 3
Formula Integrasi:
∫[a,b] f(t) dt ≈ (b-a)/2 × Σ[i=1 to 3] wᵢ · f(tᵢ)
Parameter Kuadratur:
Titik Evaluasi (xᵢ)Bobot (wᵢ)-√(3/5) ≈ -0.77465/9 ≈ 0.55560.00008/9 ≈ 0.8889+√(3/5) ≈ +0.77465/9 ≈ 0.5556
Transformasi Interval:
tᵢ = (b-a)/2 · xᵢ + (b+a)/2

Algoritma Simulasi
Langkah Simulasi:

Inisialisasi Parameter
cppt_start = 0.0s, t_end = 10.0s, Δt = 0.5s
v₀ = 0 m/s, s₀ = 0 m

Loop Simulasi (per interval Δt):

Hitung percepatan: a(t) = 3sin(t) + 0.5t²
Integrasi kecepatan: Δv = ∫[t to t+Δt] a(τ) dτ
Update kecepatan: v(t+Δt) = v(t) + Δv
Hitung jarak: Δs = v_avg × Δt
Update posisi: s(t+Δt) = s(t) + Δs
