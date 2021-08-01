<?php
require 'koneksi.php';
if(isset($_POST["token"])){
$id = $_POST["token"];
$ambil = mysqli_query($conn,"SELECT * FROM kondisi WHERE token_id=$id");
$pecah = mysqli_fetch_assoc($ambil);

$res = json_encode($pecah);
// var_dump($res);

echo $res;

}