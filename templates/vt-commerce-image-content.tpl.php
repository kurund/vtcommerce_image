


<?php if (!empty($zoom_image)) : ?>
	<a href="<?php print $zoom_image; ?>" class="cloud-zoom" rel="position: 'inside' , showTitle: false, adjustX:0, adjustY:4">
<?php endif; ?>
	
	<?php print $large_image?>
	
<?php if (!empty($zoom_image)) : ?>
	</a>
<?php endif;?>