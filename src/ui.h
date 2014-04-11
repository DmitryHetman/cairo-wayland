struct rectangle {
	int32_t x;
	int32_t y;
	int32_t width;
	int32_t height;
};

struct xkb;

struct color { double r, g, b, a; };

struct color_scheme{
	struct color *bg_color;
	struct color *font_color;
};

struct font{
	const char *family;
	cairo_font_slant_t slant;
	cairo_font_weight_t weight;
	double size;
};

struct icon{
	char *filename;
	int x, y;
	int width, height;
	cairo_surface_t *surface;
};

/* TODO remove this from here*/
struct egl_window_surface;
struct egl_ui;

struct wayland_t {
	struct wl_display *display;
	struct wl_output *output;
	struct wl_registry *registry;
	struct wl_compositor *compositor;
	struct wl_shm *shm;
	struct wl_seat *seat;
	struct wl_keyboard *keyboard;
	struct wl_pointer *pointer;
	struct wl_shell *shell;
	struct wl_data_device_manager *data_device_manager;
	struct wl_data_device *data_device;
	struct wl_surface *surface;

	int backend;
	struct egl_ui *egl;
	struct egl_window *egl_surface;

	struct shm_window *shm_surface;

	struct wl_shell_surface *shell_surface;
	struct rectangle *window_rectangle;
	struct xkb *xkb;
	struct color_scheme *color_scheme;
	char *buffer;

	int need_redraw;
	int fullscreen;

	struct font *font;

	struct icon *icon;
	int pressed;
};

struct wayland_t *init_ui(void);
void exit_ui(struct wayland_t *ui);