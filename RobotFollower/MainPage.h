String homePage1 = R"(
<!DOCTYPE html>
<html lang = en>
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

.map{
    border: 5px solid;
    border-color: #000;
    margin: 3px;
    margin-left: 10%;
    width: 70%;
    height: 600px;
} 

 .title
 {
     color: #000;
     background-color: white;
     font-family: Arial, Helvetica, sans-serif;
     font-size: 24;
     font-weight: bold;
     line-height: 1em;
     text-align: center;

     width: 30%;
     margin: 3px;
     border: 3px solid;
     border-color: darkblue;
     padding: 10px;
     margin-left: 30%;     
 }
 
 table, tr, th{
        margin-left: 30%;
        background-color: white;
        border: 3px solid;
        border-color: black;
 }

 .button{
    margin-left: 33%;
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
 .fixed-right {
    display: flex;
    position: fixed;
    top: 5%;
    left: 90%;
    right: 0;
  }
  
    input[type=range][orient=vertical]
{
    -webkit-appearance: slider-vertical; /* Chromium */
    width: 20px;
    height: 500px;
    padding: 10px;
}

</style>

<head>
  <meta charset="UTF-8">
    <title>Robot Follower</title>
    <!--script written recieved from Openlayers.org and modified by Brian O'shea-->
     <!-- Pointer events polyfill for old browsers, see https://caniuse.com/#feat=pointer -->
  <script src="https://unpkg.com/elm-pep@1.0.6/dist/elm-pep.js"></script>
  <script src="https://cdn.jsdelivr.net/gh/openlayers/openlayers.github.io@master/en/v6.13.0/build/ol.js"></script>
  <!-- The lines below are only needed for old environments like Internet Explorer and Android 4.x -->
  <script
    src="https://cdn.polyfill.io/v3/polyfill.min.js?features=fetch,requestAnimationFrame,Element.prototype.classList,TextDecoder"></script>
  <script src="https://cdnjs.cloudflare.com/ajax/libs/core-js/3.18.3/minified.js"></script>
  <script src="https://unpkg.com/gifler@0.1.0/gifler.min.js"></script>
  
</head>

<body>
    <div class = "title">
        Robot Follower
      </div>
      
      <div id = "map" class = "map">
      <script>

        let myColor = "#00ff00"
        let carColor = "#0000ff"
    )";
        //coords
String homePage2 = R"(    

        
        let zoom = 16
        let markerWidth = 20
        let markerHeight = 20
    
        ol.proj.useGeographic()
        const iconFeature = new ol.Feature({
          geometry: new ol.geom.Point([myLong, myLat]),
        });
    
        const iconFeature2 = new ol.Feature({
          geometry: new ol.geom.Point([carLong, carLat]),
        });
    
        const vectorSource = new ol.source.Vector({
          features: [iconFeature, iconFeature2],
        });
    
        const vectorLayer = new ol.layer.Vector({
          source: vectorSource,
        });
    
        const rasterLayer = new ol.layer.Tile({
          source: new ol.source.Stamen({
            layer: 'toner',
          }),
        });
    
        const map = new ol.Map({
          layers: [rasterLayer, vectorLayer],
          target: document.getElementById('map'),
          view: new ol.View({
            center: [myLong, myLat],
            zoom: zoom
          }),
        });
    
        ctx = document.createElement('canvas').getContext("2d")
        if (!iconFeature.getStyle()) {
          iconFeature.setStyle(
            new ol.style.Style({
              image: new ol.style.Icon({
                img: ctx.canvas,
                imgSize: [markerWidth, markerHeight],
                opacity: 0.6,
              }),
            })
          );
        }
        let ctx2 = document.createElement('canvas').getContext("2d")
        if (!iconFeature2.getStyle()) {
          iconFeature2.setStyle(
            new ol.style.Style({
              image: new ol.style.Icon({
                img: ctx2.canvas,
                imgSize: [markerWidth, markerHeight],
                opacity: 0.6,
              }),
            })
          );
        }
        ctx.clearRect(0, 0, markerWidth, markerHeight);
        ctx.fillStyle = myColor
        ctx.fillRect(0, 0, markerWidth, markerHeight);
        ctx2.clearRect(0, 0, markerWidth, markerHeight);
        ctx2.fillStyle = carColor;
        ctx2.fillRect(0, 0, markerWidth, markerHeight);
        map.render();
    
        // change mouse cursor when over icon
        map.on('pointermove', function (e) {
          const pixel = map.getEventPixel(e.originalEvent);
          const hit = map.hasFeatureAtPixel(pixel);
          map.getTarget().style.cursor = hit ? 'pointer' : '';
        });
      </script>
      </div>
    <div>
        <table>
            <tr>
              <th>Target type</th>
                <th>Longitude</th>
                <th>Latitude</th>
              </tr>
              <tr>
                 <td>Robot</td>
                 <td><script>document.write(carLong);</script></td>
                 <td><script>document.write(carLat);</script></td>
               </tr>
               <tr>
                 <td>User</td>
                 <td><script>document.write(myLong);</script></td>
                 <td><script>document.write(myLat);</script></td>
               </tr>
        </table>
    </div>
</body>
</html>
)";
