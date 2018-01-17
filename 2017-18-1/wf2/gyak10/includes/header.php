<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta http-equiv="X-UA-Compatible" content="ie=edge">
  <title></title>
  <link rel="stylesheet" href="https://bootswatch.com/4/flatly/bootstrap.min.css">
</head>
<body>
  <nav class="navbar navbar-expand navbar-dark bg-primary">
    <a class="navbar-brand" href="index.php">Beadandó-kezelő</a>
    <ul class="navbar-nav mr-auto">
      <li class="nav-item"><a class="nav-link" href="index.php">Feladatok</a></li>
      <li class="nav-item"><a class="nav-link" href="feladatlista.php">Feltöltött fájlok</a></li>
    </ul>
    <form action="login.php" class="form-inline my-2 my-lg-0 float-right">
      <input class="form-control mr-sm-2 bg-primary text-white" type="text" placeholder="Felhasználó">
      <input class="form-control mr-sm-2 bg-primary text-white" type="text" placeholder="Jelszó">
      <input class="btn btn-secondary" type="submit" value="Login">
    </form>
  </nav>