# IoT-lamp
kode untuk program iot lampu pada web server dan arduino


1. untuk membuat web Server terdapat 7 file yang harus didownload yaitu get.php , hidup.php , index.php , kondisi(1).sql , koneksi.php , mati.php , style.css
2. masukan file ke vps cloud atau hosting kalian yang tidak memiliki SSL atau kalian dapat menonaktifkan SSL pada hosting, lalu import file kondisi(1).sql ke database pada hosting
3. jangan lupa untuk mengubah koneksi.php, sesuaikan pada database yang kalian gunakan
4. lalu test file get.php pada postman untuk mengetest API nya
5. jika sudah beres pada web server lalu program hardwarenya
6. isi nama wifi dan pass dan masukan url kalian untuk melakukan request http
7. setelah itu upload program ke hardware
8. jika sudah cek kembali apakah program bekerja melalui serial monitor
9. terima kasih
