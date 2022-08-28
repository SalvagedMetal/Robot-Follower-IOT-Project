String page2 = R"###(
<!DOCTYPE html>
<html>
<head>
<style>
.flex-container {
  display: flex;
  height: 600px;
  flex-wrap: wrap;
  align-content: space-between;
  background-color: DodgerBlue;
}

.flex-container > div {
  background-color: #a0a0a0;
  width: 100px;
  margin: 10px;
  text-align: center;
  line-height: 75px;
  font-size: 30px;
}
</style>
</head>
<body>
<h1>The align-content Property</h1>

<p>The "aligndfh gdfh sdf sdf sg-content: space-between;" displays the flex lines with equal space between them:</p>

<div class="flex-container">
  <div>1</div>
  <div>2</div>
  <div>3</div>  
  <div>4</div>
  <div>5</div>
  <div>6</div>  
  <div>7</div>
  <div>8</div>
  <div>9</div>  
  <div>10</div>
  <div>11</div>
  <div>12</div>  
</div>

</body>
</html>
)###";
