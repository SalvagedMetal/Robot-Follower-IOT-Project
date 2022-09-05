String pagePicker = R"(
<!DOCTYPE html>
<style>
body {
    background-color: #70a7ff;
    color: #000;
    font-family: Arial, Helvetica, sans-serif;
    font-size: 32px;
    font-weight: normal;
    line-height: 1.6em;
    margin: 0;
}
.button{
    margin-left: 20%;
    margin-top: 5px;
    background-color: #0c4887;
    padding: 24px 36px;
    transition-duration: 0.5;

    text-align: center;
    color: white;
    font-size: 24px;
 }
 .button:hover{
     background-color: #177fff;
     color: black;
 }
</style>

<head>
    <title>Choose Page</title>
    <link rel="stylesheet" type="text/css" href="Style.css">
</head>
<body>
    <div>
        <a class = "button" href="/HomePage" role = "button">Home Page</a>
        <a class = "button" href = "/Phone" role = "button">Phone page</a>
    </div>
</body>
</html>
)";
