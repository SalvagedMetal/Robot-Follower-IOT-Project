String homePage = R"###(
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <title>Dive Into HTML5</title>
</head>
<body>
  <p id="demo">
  <script> 
  <!--Script written by Brian O'shea and modified by Iwo Kania -->
 // window.location = window.location.replace(//,*$/,'');
    let gpsCoords = {};
    if (!navigator.geolocation) {
      document.getElementById("demo").innerHTML = `Your browser doesn't support Geolocation`;
    } else {
      document.getElementById("demo").innerHTML = `Your browser supports Geolocation`;
      navigator.geolocation.getCurrentPosition(onSuccess, onError);
    }
  
    function onSuccess(position) {
     
        let {
            latitude,
            longitude
        } = position.coords;
        
        gpsCoords = position.coords;
        document.getElementById("demo").innerHTML = `Your location: (${latitude},${longitude})`;
       location.href = "/data?lat=" + gpsCoords.latitude + "&long=" + gpsCoords.longitude + "";
        
    } 
  
  function onError() {
        document.getElementById("demo").innerHTML = `Failed to get your location!`;
    }
    
  </script>
</body>
</html>
)###"; 
