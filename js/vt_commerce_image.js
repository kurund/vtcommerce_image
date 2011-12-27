jQuery(document).ready(function ($) {
	// we need this because Drupal Commerce has ajax script on product display page
	// without this the bubbling will failed
	Drupal.behaviors.vtCommerceImage = { attach: function() {
		attach();
	}}
	
	attach();
	
	function attach() {
		var option = Drupal.settings.vt_commerce_image,
		    clouds = $('.cloud-zoom');
		
		if (option.zoom == 'yes') {
		  clouds.CloudZoom();
		}

		  // initialization
	    // This is very important steps because jQuery cloud js need the element
	    // to be visible when intialized, so we cannot just plain hide the
	    // large element, instead we use z-index to hide the element and 
	    // show the first element on load
	    ul = $('.cloud-zoom').parents('.vt-commerce-image-wrapper'); // your parent element
	    
	    // reorder the zindex so the first element will be always shown first
	    var z = 9000;
	    ul.find('.wrap').each(function() {
	      $(this).css('z-index',  z );
	      z--;
	    });
	  
	    // declare variables
	    var parents = clouds.parents('.vt-commerce-image-wrapper'),
	        cHeight = clouds.find('img').height(),
	        cWidth = clouds.find('img').width();
	    
	    // create the thumbnail wrapper so we can add thumbnail child here later on
	    parents.css('position', 'relative').append('<div class="cloud-thumbnail"/>');
	  
	    // cloning the large image to create a thumbnail navigation
	    clouds.each(function() {
	      var thumbClone = $(this).find('img').clone().width(50).height(50);
	      thumbClone.appendTo('.cloud-thumbnail').addClass('thumbsmall').wrap('<div class="cloud-thumbwrapper" />');
	      
	    });
	    
	    // function for the thumbnail to show the right large image
	    $('.thumbsmall').each(function(){      
	      $(this).click(function() {
	        var index = $('.thumbsmall').index(this);
	        clouds.parents('.wrap').fadeOut(100);
	        clouds.eq(index).parents('.wrap').fadeIn(800);  
	        $('.thumbsmall').removeClass('active');
	        $(this).addClass('active');	        
	      });
	    }).eq(0).addClass('active');

	    
      if (option.hoverZoom == 1) {
        $('.cloud-thumbnail .cloud-thumbwrapper').width(50).height(50).imageEnlarge({
          multiple: 1.2,
          mouseInSpeed : 300,
          mouseOutSpeed : 300,
          zindex : 600,
          topOffset : -5,
          leftOffset : -5
        });
      }
	}
});