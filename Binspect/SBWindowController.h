//
//  SBWindowController.h
//  Binspect
//
//  Created by Joe Savage on 24/10/2014.
//

#import <Cocoa/Cocoa.h>
#import "SBCurveView.h"

@interface SBWindowController : NSWindowController <NSTableViewDelegate, NSTableViewDataSource, SBCurveViewDelegate>
{
	         NSUInteger          _selectionRegionStartIndex, _selectionRegionEndIndex;
	         NSString            *_filePath;
	         NSData              *_data;
	         NSInteger           _zoomLevel, _hoverRegionSize;
	IBOutlet NSSegmentedControl  *_curveTypeSegmentedControl;
	IBOutlet NSSegmentedControl  *_curveColouringSegmentedControl;
	IBOutlet SBCurveView         *_curveView;
	IBOutlet NSProgressIndicator *_curvePanelProgressIndicator;
	IBOutlet NSTextField         *_fileNameLabel, *_fileSizeLabel, *_fileSizeHexLabel, *_fileEntropyLabel;
	IBOutlet NSTextField         *_hoveredMemoryAddressLabel, *_hoveredRegionMemoryAddressRangeLabel;
	IBOutlet NSTableView         *_hexTableView;
}

- (id) init;
- (void) dealloc;

+ (CGFloat) calculateShannonEntropy:(NSData *)data fromIndex:(NSInteger)index forBlockSize:(NSInteger)blocksize;

- (NSString *) windowTitleForDocumentDisplayName:(NSString *)displayName;
- (BOOL) openFile:(NSString *)filename;
- (void) presentOpenDialog;
- (void) changeSegmentedControl:(NSSegmentedControl *)segmentedControl toIndex:(NSInteger)index;
- (void) updateFileLabels;
- (void) initiateWindowAction;
- (void) windowDidLoad;
- (void) windowWillClose:(NSNotification *)notification;

- (IBAction) segmentedControlClicked:(id)sender;

// NSTableViewDelegate Protocol Delegate Methods
- (NSView *) tableView:(NSTableView *)tableView viewForTableColumn:(NSTableColumn *)tableColumn row:(NSInteger)row;

// NSTableViewDataSource Protocol Delegate Methods
- (NSInteger) numberOfRowsInTableView:(NSTableView *)tableView;

// SBCurveViewDelegate Protocol Delegate Methods
- (void) curveViewMouseMovedToInvalidIndex;
- (void) curveViewMouseMovedToIndex:(NSInteger)index;

// First-responder event handlers
- (IBAction) copy:(id)sender;
- (IBAction) zoomIn:(id)sender;
- (IBAction) zoomOut:(id)sender;
- (IBAction) reload:(id)sender;
- (IBAction) selectPrimaryCurveType:(id)sender;
- (IBAction) selectSecondaryCurveType:(id)sender;
- (IBAction) selectPrimaryCurveColouringMode:(id)sender;
- (IBAction) selectSecondaryCurveColouringMode:(id)sender;
- (IBAction) selectTertiaryCurveColouringMode:(id)sender;

@end
