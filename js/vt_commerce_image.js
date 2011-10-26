jQuery(document).ready(function ($) {
	// we need this because Drupal Commerce has ajax script on product display page
	// without this the bubbling will failed
	Drupal.behaviors.vtCommerceImage = { attach: function() {
		attach();
	}}
	
	attach();
	
	function attach() {
		var option = Drupal.settings.vt_commerce_image;
		if (option.zoom == 'yes') {
			var iLarge = $('.wrap');
			$('.cloud-zoom, .cloud-zoom-gallery').CloudZoom();
		} else {
			var iLarge = $('.vt-commerce-image-large img');
		}
		
		$('.wrap').fadeOut().eq(0).fadeIn();
		 $('.vt-commerce-preview .vt-commerce-image-wrapper').each(function() {
				$(this).imageEnlarge({
					multiple: 1.2,
					mouseInSpeed : 300,
					mouseOutSpeed : 300,
					zindex : 600,
					topOffset : -5,
					leftOffset : -5
				});
				
				$(this).click(function(){
					var i = $('div.vt-commerce-image-wrapper').index(this);
					iLarge.fadeOut('slow');
					iLarge.eq(i).fadeIn('fast');
				});
		 });
	}
});