#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

// Struktur untuk menyimpan data setiap titik waktu dalam simulasi
typedef struct {
    double time;         // waktu (detik)
    double acceleration; // percepatan instantan (m/s²)
    double velocity;     // kecepatan kumulatif (m/s)
    double distance;     // jarak tempuh kumulatif (meter)
} DataPoint;

// Fungsi percepatan kendaraan berdasarkan waktu
// Menggunakan kombinasi fungsi trigonometri dan kuadratik untuk simulasi realistis
double accelerationFunction(double t) {
    return 3 * sin(t) + 0.5 * t * t;
}

// Implementasi metode Gaussian Quadrature orde 3 untuk integrasi numerik
// Menghitung integral dari fungsi f pada interval [a,b] dengan presisi tinggi
double gaussQuadrature(double (*f)(double), double a, double b) {
    // Titik evaluasi untuk kuadratur Gauss-Legendre orde 3
    double x[] = { -sqrt(3.0/5.0), 0.0, sqrt(3.0/5.0) };
    // Bobot untuk setiap titik evaluasi
    double w[] = { 5.0/9.0, 8.0/9.0, 5.0/9.0 };
    
    double integral = 0.0;
    
    // Evaluasi integral menggunakan formula kuadratur
    for (int i = 0; i < 3; ++i) {
        // Transformasi dari interval standar [-1,1] ke interval [a,b]
        double t_i = ((b - a) / 2.0) * x[i] + ((b + a) / 2.0);
        integral += w[i] * f(t_i);
    }
    
    // Faktor skala untuk transformasi interval
    return ((b - a) / 2.0) * integral;
}

int main() {
    // Parameter simulasi
    double t_start = 0.0;   // waktu mulai simulasi
    double t_end = 10.0;    // waktu akhir simulasi
    double delta_t = 0.5;   // interval waktu untuk diskretisasi
    
    // Kontainer untuk menyimpan semua data simulasi
    vector<DataPoint> data;
    
    // Variabel state kendaraan
    double current_velocity = 0.0;  // kecepatan saat ini (kondisi awal diam)
    double current_distance = 0.0;  // jarak tempuh total
    
    // Membuat file CSV untuk output data
    ofstream outfile("hasil_simulasi.csv");
    outfile << "Time,Acceleration,Velocity,Distance" << endl;
    
    // Loop simulasi utama dengan interval waktu tetap
    for (double t = t_start; t <= t_end; t += delta_t) {
        // Hitung percepatan instantan pada waktu t
        double acc = accelerationFunction(t);
        
        // Hitung perubahan kecepatan menggunakan integrasi Gaussian Quadrature
        // ?v = ?[t to t+?t] a(t) dt
        double delta_v = gaussQuadrature(accelerationFunction, t, t + delta_t);
        
        // Update kecepatan total
        current_velocity += delta_v;
        
        // Hitung kecepatan rata-rata dalam interval untuk menghitung jarak
        // Menggunakan metode trapezoidal: v_avg = v_awal + ?v/2
        double avg_velocity = current_velocity - delta_v / 2.0;
        
        // Update jarak tempuh menggunakan kecepatan rata-rata
        // ?s = v_avg × ?t
        current_distance += avg_velocity * delta_t;
        
        // Simpan data point untuk output
        data.push_back({t, acc, current_velocity, current_distance});
        
        // Tulis ke file CSV dengan format 4 desimal
        outfile << fixed << setprecision(4)
                << t << "," << acc << "," << current_velocity << "," << current_distance << endl;
    }
    
    // Tutup file output
    outfile.close();
    
    // Tampilkan hasil simulasi ke konsol
    cout << "\nHasil Simulasi Performa Kendaraan:\n";
    cout << left << setw(10) << "Waktu" << setw(15) << "Percepatan" << setw(15) << "Kecepatan" << setw(15) << "Jarak" << endl;
    
    // Loop untuk menampilkan semua data point
    for (const auto& d : data) {
        cout << setw(10) << d.time << setw(15) << d.acceleration
             << setw(15) << d.velocity << setw(15) << d.distance << endl;
    }
    
    // Tampilkan ringkasan hasil akhir simulasi
    cout << "\nTotal jarak tempuh: " << current_distance << " meter" << endl;
    cout << "Kecepatan akhir: " << current_velocity << " m/s" << endl;
    
    return 0;
}
