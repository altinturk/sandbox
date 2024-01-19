<!-- ****************************************************************************** -->
<!-- 2018/ file download sample 1 -->

<?php
echo Button-info-icon.png
$aContext = array('http' => array('request_fulluri' => true));
$cxContext = stream_context_create($aContext);
file_put_contents('myfile', file_get_contents('http://website.com/path/Button-info-icon.png', False, $cxContext));
echo done

?>

<!-- ****************************************************************************** -->
<!-- 2018/ file download sample over proxy -->
<?php
$aContext = array(
    'http' => array(
        'proxy' => 'tcp://proxy.server.address:3128',
        'request_fulluri' => true,
    ),
);
$cxContext = stream_context_create($aContext);

$sFile = file_get_contents("http://website.com/path/1.jpg", False, $cxContext);
file_put_contents("phpget/profile.jpg", file_get_contents("http://website.com/path/photo1.jpg", False, $cxContext));

// imagejpeg($sFile);
// header("Content-type: image/jpeg");
echo "ok";
?>


<!-- ****************************************************************************** -->
<!-- 2018/ visitor quick tips - user info -->
<?
    $_SERVER['REMOTE_ADDR']; //- This contains the real IP address of the client. That is the most reliable value you can find from the user.
    $_SERVER['REMOTE_HOST']; //- This will fetch the Host name from which the user is viewing the current page. But for this script to work, Hostname Lookups On inside httpd.conf must be configured.
    $_SERVER['HTTP_CLIENT_IP']; //- This will fetch the IP address when user is from Shared Internet services.
    $_SERVER['HTTP_X_FORWARDED_FOR']; //- This will fetch the IP address from the user when he is behind the proxy
?>