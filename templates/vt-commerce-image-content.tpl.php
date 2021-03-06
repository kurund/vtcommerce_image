<?php
/**
 * Template for vt commerce image module.
 * Available variable :
 * $zoom_image = the extra large image used for zooming
 * $large_image = the initially displayed image
 * $thumbnail = thumbnail image
 *
 */

?>

<?php // build the wrapper to link this to cloud zoom js ?>
<?php if (!empty($zoom_image)) : ?>
  <a href="<?php print $zoom_image; ?>" class="cloud-zoom" rel="<?php print $relvalue;?>">
<?php endif; ?>


<?php // print the image regardless of cloud zoom this is useful for js fallback ?>
<?php print $large_image;?>

<?php // print the thumbnail image ?>
<img class="vt-thumbnail" src="<?php print $thumbnail['path'];?>" title="<?php print $thumbnail['title'];?>"
     alt="<?php print $thumbnail['alt'];?>">

<?php // print the wrapper closure ?>
<?php if (!empty($zoom_image)) : ?></a><?php endif;?>
