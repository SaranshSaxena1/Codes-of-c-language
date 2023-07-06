#include <stdio.h>

int main() {
    int num_frames, num_pages, faults = 0;
    int frames[10], pages[30], last_used[10];
    
    printf("Enter number of frames: ");
    scanf("%d", &num_frames);
    
    printf("Enter number of pages: ");
    scanf("%d", &num_pages);
    
    printf("Enter page reference string: ");
    for (int i = 0; i < num_pages; i++) {
        scanf("%d", &pages[i]);
    }
    
    for (int i = 0; i < num_frames; i++) {
        frames[i] = -1;
        last_used[i] = -1;
    }
    
    for (int i = 0; i < num_pages; i++) {
        int page = pages[i];
        int frame_index = -1;
        
        // Check if page is already in a frame
        for (int j = 0; j < num_frames; j++) {
            if (frames[j] == page) {
                frame_index = j;
                break;
            }
        }
        
        if (frame_index == -1) {
            // Find the most recently used frame to replace
            int max_last_used = last_used[0];
            frame_index = 0;
            for (int j = 1; j < num_frames; j++) {
                if (last_used[j] > max_last_used) {
                    max_last_used = last_used[j];
                    frame_index = j;
                }
            }
            
            // Replace the page in the frame
            frames[frame_index] = page;
            faults++;
        }
        
        // Update the last used time of the frame
        last_used[frame_index] = i;
        
        // Print the current state of the frames
        printf("Frames: ");
        for (int j = 0; j < num_frames; j++) {
            if (frames[j] == -1) {
                printf("- ");
            } else {
                printf("%d ", frames[j]);
            }
        }
        printf("\n");
    }
    
    printf("\nTotal page faults: %d\n", faults);
    
    return 0;
}
