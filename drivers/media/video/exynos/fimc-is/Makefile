fimc-is-objs	:= fimc-is-core.o \
		fimc-is-mem.o \
		fimc-is-framemgr.o \
		fimc-is-groupmgr.o \
		fimc-is-resourcemgr.o \
		fimc-is-video.o \
		fimc-is-video-sensor.o \
		fimc-is-video-3aa.o \
		fimc-is-video-3aac.o \
		fimc-is-video-isp.o \
		fimc-is-video-scc.o \
		fimc-is-video-scp.o \
		fimc-is-video-vdisc.o \
		fimc-is-video-vdiso.o \
		fimc-is-hw-csi.o \
		fimc-is-hw-ischain.o \
		fimc-is-subdev-ctrl.o \
		fimc-is-device-csi.o \
		fimc-is-device-flite.o \
		fimc-is-device-sensor.o \
		fimc-is-device-ischain.o \
		fimc-is-interface.o \
		fimc-is-time.o \
		fimc-is-dvfs.o \
		fimc-is-dt.o \
		fimc-is-clk-gate.o

obj-$(CONFIG_USE_VENDER_FEATURE) := fimc-is-spi.o \
				fimc-is-sec-define.o \
				crc32.o

obj-$(CONFIG_COMPANION_USE)	+= fimc-is-companion.o \
				fimc-is-fan53555.o \
				fimc-is-device-companion.o \
				fimc-is-video-companion.o

obj-$(CONFIG_VIDEO_EXYNOS_FIMC_IS) += fimc-is.o

obj-y += sensor/
