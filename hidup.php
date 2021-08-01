<?php
require 'koneksi.php';
if(isset( $_GET["id"])){
$id = $_GET["id"];

mysqli_query($conn, "UPDATE kondisi SET lampu=1 WHERE token_id='$id'");

echo "<script>
    alert('lampu menyala');
    document.location.href = 'index.php';
</script>";

}